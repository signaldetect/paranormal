#include "action.h"

Action::Action()
{
}

void Action::windowCreating(const sf::VideoMode& mode, const sf::String& title,
                            bool vsync)
{
  create(mode, title);
  setVerticalSyncEnabled(vsync);
}

void Action::windowActivationChanging(bool active)
{
  if (activate(active))
    actualize<p__the(ActionEffector::actionActivationChanged)>(active);
}

void Action::gamePlaying()
{
  if (isOpen()) {
    // Activates and displays the window
    if (activate(/*active=*/true))
      display();
    // Processes a system events
    processEvents();
  }
}

void Action::gameStopped()
{
  close();
}

void Action::onCreate()
{
  actualize<p__the(ActionEffector::actionWindowCreated)>();
}

void Action::onResize()
{
  actualize<p__the(ActionEffector::actionWindowResized)>
           (/*new_size=*/getSize());
}

bool Action::activate(bool active)
{
  if (setActive(active))
    return true;
  // else => activation is failed
  actualize<p__the(ActionEffector::actionActivationFailed)>();
  return false;
}

void Action::processEvents()
{
  // Event loop
  while (pollEvent(event)) {
    if (event.type == sf::Event::Closed) {
      // Close window requested
      actualize<p__the(ActionEffector::actionWindowClosed)>();
    }
    else if (event.type == sf::Event::KeyPressed) {
      // Keyboard button pressed
      actualize<p__the(ActionEffector::actionKeyPressed)>(event.key);
    }
  }
}
