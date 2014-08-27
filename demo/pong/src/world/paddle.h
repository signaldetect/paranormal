#ifndef _WORLD_PADDLE_H_
#define _WORLD_PADDLE_H_

#include <p/eventer.h>
#include <string>
#include <SFML/Window/Keyboard.hpp>

#include "geom/movablerectfigure.h"

// Actualizer
#include "paddleeffector.h"

// Effectors
#include "../contrib/configeffector.h" // + Nodes, Settings
#include "../proc/timereffector.h" // + sf::Time
#include "fieldeffector.h" // + MovableRect, Impact
#include "balleffector.h" // + MovableRect
#include "../gameeffector.h"

class Paddle : public p::Eventer<p::Act<PaddleEffector>,
                                 p::Ext<MovableRectFigure>,
                                 ConfigEffector,
                                 TimerEffector,
                                 FieldEffector,
                                 BallEffector,
                                 GameEffector> {
private:
  const std::string mark;

  // Up/down control keys
  sf::Keyboard::Key keyUp;
  sf::Keyboard::Key keyDown;

public:
  Paddle(const std::string& unique_mark);

  // Effects

  // * Config
  p__inc(configNodeParsed, const Nodes& nodes, const Settings& settings)

  // * Timer
  p__inc(timerStepped, const sf::Time& time_step)

  // * Field
  p__inc(fieldTopCollided,
         const MovableRect& collided_rect, const Impact& impact)
  p__inc(fieldBottomCollided,
         const MovableRect& collided_rect, const Impact& impact)

  // * Ball
  p__inc(ballMoving, const MovableRect& moving_rect)

  // * Game
  p__inc(gameStarted)
};

#endif /*_WORLD_PADDLE_H_*/
