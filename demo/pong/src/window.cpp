#include "window.h"

Window::Window()
{
  setSize(sf::Vector2u(/*x=*/800, /*y=*/600));
  setTitle("Pong!");
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
  clear();
  //
  if (isOpen())
    actualize<p__the(WindowEffector::windowRendering)>(/*render=*/*this);
  else
    actualize<p__the(WindowEffector::windowClosed)>();
}
