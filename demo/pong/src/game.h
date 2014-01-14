#ifndef _GAME_H_
#define _GAME_H_

#include <p/eventer.h>

// Actualizer
#include "gameeffector.h"

// Effectors
#include "contrib/resourceeffector.h" // + std::string
#include "proc/actioneffector.h" // + sf::Event

// Internals
#include "contrib/resource.h"
#include "proc/action.h"
#include "proc/timer.h"
#include "view/window.h"
#include "view/score.h"
#include "view/informer.h"
#include "world/field.h"
#include "world/ball.h"
#include "world/paddle.h"

class Game : public p::Eventer<p::Act<GameEffector>,
                               ResourceEffector,
                               ActionEffector> {
private:
  enum State {LAUNCHED, PLAYING, STOPPED};
  State state;

  Resource resource;
  Action action;
  Timer timer;
  Window window;
  Score score;
  Informer informer;
  Field field;
  Ball ball;
  Paddle paddleLeft;
  Paddle paddleRight;

public:
  Game();

  // Effects (Resource)
  void resourceErrorDetected(const std::string& message) override;

  // Effects (Action)
  void actionWindowClosed() override;
  void actionKeyPressed(const sf::Event::KeyEvent& key) override;

private:
  void launch();
  void start();
  void play();
  void stop();
};

#endif /*_GAME_H_*/
