#ifndef _WORLD_BALL_H_
#define _WORLD_BALL_H_

#include <p/eventer.h>
#include <SFML/System/Vector2.hpp> // + sf::Vector2f

#include "geom/movablerectfigure.h"

// Actualizer
#include "balleffector.h"

// Effectors
#include "../contrib/resourceeffector.h" // + ConfigNode
#include "../proc/timereffector.h" // + sf::Time
#include "fieldeffector.h" // + MovableRect, Impact
#include "paddleeffector.h" // + MovableRect, Impact
#include "../gameeffector.h"

class Ball : public p::Eventer<p::Act<BallEffector>,
                               p::Ext<MovableRectFigure>,
                               ResourceEffector,
                               TimerEffector,
                               FieldEffector,
                               PaddleEffector,
                               GameEffector> {
public:
  Ball();

  // Effects (Resource)
  void resourceConfigLoading(const ConfigNode& node) override;

  // Effects (Timer)
  void timerStepped(const sf::Time& time_step) override;

  // Effects (Field)
  void fieldLeftPassed() override;
  void fieldRightPassed() override;
  void fieldTopCollided(const MovableRect& collided_rect,
                        const Impact& impact) override;
  void fieldBottomCollided(const MovableRect& collided_rect,
                           const Impact& impact) override;

  // Effects (Paddle)
  void paddleMoving(const MovableRect& moving_rect) override;
  void paddleBallReturned(const Impact& impact) override;

  // Effects (Game)
  void gameStarted() override;

private:
  void initialize();

  void randomizeDir();
  void randomizeDirHorz();
  void randomizeDirVert();
};

#endif /*_WORLD_BALL_H_*/
