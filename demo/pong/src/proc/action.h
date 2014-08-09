#ifndef _PROC_ACTION_H_
#define _PROC_ACTION_H_

#include <p/eventer.h>
#include <SFML/Window/Window.hpp>
#include <SFML/Window/Event.hpp>

// Actualizer
#include "actioneffector.h"

// Effectors
#include "../view/windoweffector.h" // + sf::VideoMode, sf::String
#include "../gameeffector.h"

class Action : public p::Eventer<p::Act<ActionEffector>,
                                 p::Ext<sf::Window>,
                                 WindowEffector,
                                 GameEffector> {
private:
  sf::Event event;

public:
  // Effects (Window)
  void windowCreating(const sf::VideoMode& mode, const sf::String& title,
                      bool vsync) override;
  void windowActivationChanging(bool active) override;

  // Effects (Game)
  void gamePlaying() override;
  void gameStopped() override;

protected:
  void onCreate() override;
  void onResize() override;

private:
  bool activate(bool active);
  void processEvents();
};

#endif /*_PROC_ACTION_H_*/
