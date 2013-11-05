#ifndef _WINDOW_H_
#define _WINDOW_H_

#include <p/eventer.h>
#include <SFML/Graphics/RenderWindow.hpp>

// Actualizer
#include "windoweffector.h"

// Effectors
#include "gameeffector.h"

class Window : public p::Eventer<Window,
                                 p::Act<WindowEffector>,
                                 p::Ext<sf::RenderWindow>,
                                 GameEffector> {
public:
  Window();

  // Effects (Game)
  void gameLaunched();
  void gamePlaying();
};

#endif /*_WINDOW_H_*/
