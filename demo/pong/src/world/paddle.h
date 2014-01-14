#ifndef _WORLD_PADDLE_H_
#define _WORLD_PADDLE_H_

#include <p/eventer.h>
#include <string>
#include <SFML/Window/Keyboard.hpp>

#include "geom/movablerectfigure.h"

// Actualizer
#include "paddleeffector.h"

// Effectors
#include "../contrib/resourceeffector.h" // + ConfigNode
#include "../proc/timereffector.h" // + sf::Time
#include "fieldeffector.h" // + MovableRect, Impact
#include "balleffector.h" // + MovableRect
#include "../gameeffector.h"

class Paddle : public p::Eventer<p::Act<PaddleEffector>,
                                 p::Ext<MovableRectFigure>,
                                 ResourceEffector,
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

  // Effects (Resource)
  void resourceConfigLoading(const ConfigNode& node) override;

  // Effects (Timer)
  void timerStepped(const sf::Time& time_step) override;

  // Effects (Field)
  void fieldTopCollided(const MovableRect& collided_rect,
                        const Impact& impact) override;
  void fieldBottomCollided(const MovableRect& collided_rect,
                           const Impact& impact) override;

  // Effects (Ball)
  void ballMoving(const MovableRect& moving_rect) override;

  // Effects (Game)
  void gameStarted() override;
};

#endif /*_WORLD_PADDLE_H_*/
