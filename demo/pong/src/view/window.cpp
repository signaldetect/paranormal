#include <string>
#include <SFML/Window/VideoMode.hpp>
#include <SFML/System/String.hpp>

#include "window.h"

sf::Vector2u Window::getSize() const
{
  return size;
}

void Window::configNodeParsed(const Nodes& nodes, const Settings& settings)
{
  if (nodes.active("window")) {
    std::string title;
    // Initializes the window view
    if (settings("width", "height", "title") >> size.x >> size.y >> title) {
      // Sets the vertical synchronization
      bool vsync = true; // enable by default
      if (settings.contains("vsync"))
        settings("vsync") >> vsync;
      // Creates the window
      //setupView(width, height, title, vsync);
      actualize<p__the(WindowEffector::windowCreating)>
               (sf::VideoMode(size.x, size.y), sf::String(title), vsync);
    }
  }
}

void Window::figureDrawingReady(const sf::Drawable& drawable)
{
  drawables.emplace_back(drawable);
}

void Window::actionWindowCreated()
{
  // Initializes the render target
  initialize();
}

void Window::actionWindowResized(const sf::Vector2u& new_size)
{
  size = new_size;
  // Updates the current view
  setView(getView());
}

void Window::actionActivationChanged(bool active)
{
  state = (active ? ACTIVATED : DEACTIVATED);
}

void Window::actionActivationFailed()
{
  state = FAILED;
}

void Window::gamePlaying()
{
  clear();
  // Draws all drawable objects
  Drawables::const_iterator it;
  for (it = drawables.begin(); it != drawables.end(); ++it)
    draw(/*drawable=*/(*it).get());
}

void Window::gameStopped()
{
  // ...
}

bool Window::activate(bool active)
{
  // Makes change activation request
  if ((active && (state != ACTIVATED)) || (!active && (state != DEACTIVATED)))
    actualize<p__the(WindowEffector::windowActivationChanging)>(active);
  //
  return (state != FAILED);
}
