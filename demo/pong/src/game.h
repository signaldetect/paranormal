#ifndef _GAME_H_
#define _GAME_H_

#include <p/eventer.h>

// Actualizer
#include "gameeffector.h"

// Effectors
#include "windoweffector.h"

// Internals
#include "window.h"
#include "field.h"
#include "ball.h"
#include "paddle.h"

class Game : public p::Eventer<Game,
                               p::Act<GameEffector>,
                               WindowEffector> {
private:
  Window window;
  Field field;
  Ball ball;
  Paddle paddle;

  bool playing;

public:
  Game();

  // Effects (Window)
  void windowRendering(sf::RenderTarget& render);
  void windowClosed();

private:
  void play();
};

#endif /*_GAME_H_*/
