#include <string>
#include <SFML/Window/VideoMode.hpp>
#include <SFML/System/String.hpp>

#include "window.h"

Window::Window()
{
}

sf::Vector2u Window::getSize() const
{
  return size;
}

void Window::resourceConfigLoading(const ConfigNode& node)
{
  if (node.is("window")) {
    std::string title;
    // Initializes the window view
    if ((node["width"] >> size.x) && (node["height"] >> size.y) &&
        (node["title"] >> title)) {
      // Sets the vertical synchronization
      bool vsync = true; // enable by default
      if (node.contains("vsync"))
        node["vsync"] >> vsync;
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
