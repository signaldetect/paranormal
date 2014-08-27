#ifndef _WORLD_BALL_H_
#define _WORLD_BALL_H_

#include <p/eventer.h>
#include <SFML/System/Vector2.hpp> // + sf::Vector2f

#include "geom/movablerectfigure.h"

// Actualizer
#include "balleffector.h"

// Effectors
#include "../contrib/configeffector.h" // + Nodes, Settings
#include "../proc/timereffector.h" // + sf::Time
#include "fieldeffector.h" // + MovableRect, Impact
#include "paddleeffector.h" // + MovableRect, Impact
#include "../gameeffector.h"

class Ball : public p::Eventer<p::Act<BallEffector>,
                               p::Ext<MovableRectFigure>,
                               ConfigEffector,
                               TimerEffector,
                               FieldEffector,
                               PaddleEffector,
                               GameEffector> {
public:
  // Effects

  // * Config
  p__inc(configNodeParsed, const Nodes& nodes, const Settings& settings)

  // * Timer
  p__inc(timerStepped, const sf::Time& time_step)

  // * Field
  p__inc(fieldLeftPassed)
  p__inc(fieldRightPassed)
  p__inc(fieldTopCollided,
         const MovableRect& collided_rect, const Impact& impact)
  p__inc(fieldBottomCollided,
         const MovableRect& collided_rect, const Impact& impact)

  // * Paddle
  p__inc(paddleMoving, const MovableRect& moving_rect)
  p__inc(paddleBallReturned, const Impact& impact)

  // * Game
  p__inc(gameStarted)

private:
  void initialize();

  void randomizeDir();
  void randomizeDirHorz();
  void randomizeDirVert();
};

#endif /*_WORLD_BALL_H_*/
