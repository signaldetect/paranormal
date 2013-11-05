#ifndef _GAME_H_
#define _GAME_H_

#include <p/eventer.h>

// Actualizer
#include "gameeffector.h"

// Effectors
#include "windoweffector.h"

// Internals
#include "window.h"
#include "ball.h"

class Game : public p::Eventer<Game,
                               p::Act<GameEffector>,
                               WindowEffector> {
private:
  Window window;
  Ball ball;

  bool playing;

public:
  Game();

  // Effects (Window)
  void windowClosed();

private:
  void play();
};

#endif /*_GAME_H_*/
