#include <SFML/Window/Event.hpp>
#include <SFML/Window/Keyboard.hpp>

#include "window.h"

Window::Window(unsigned int width, unsigned int height,
               const sf::String& title)
{
  create(sf::VideoMode(width, height), title);
  setVerticalSyncEnabled(true);
}

void Window::gameLaunched()
{
}

void Window::gamePlaying()
{
  sf::Event event;
  while (pollEvent(event)) {
    if ((event.type == sf::Event::Closed) ||
        ((event.type == sf::Event::KeyPressed) &&
         (event.key.code == sf::Keyboard::Escape)))
      close();
  }
  //
  if (isOpen()) {
    clear();
    actualize<p__the(WindowEffector::windowRendering)>(/*render=*/*this);
    display();
  }
  else
    actualize<p__the(WindowEffector::windowClosed)>();
}
