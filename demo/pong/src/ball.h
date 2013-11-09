#ifndef _BALL_H_
#define _BALL_H_

#include <p/eventer.h>
#include <SFML/System/Vector2.hpp> /* sf::Vector2f, sf::Vector2i */
#include <SFML/Graphics/RenderTarget.hpp>

#include "rectangle.h"

// Actualizer
#include "balleffector.h"

// Effectors
#include "fieldeffector.h"
#include "paddleeffector.h"
#include "windoweffector.h"

class Ball : public p::Eventer<p::Act<BallEffector>,
                               p::Ext<Rectangle>,
                               FieldEffector,
                               PaddleEffector,
                               WindowEffector> {
private:
  const sf::Vector2f initial; // initial position
  sf::Vector2i direction;

  float offset = 0.0f;

public:
  Ball(const sf::Vector2f& pos, const sf::Vector2f& size);

  // Effects (Field)
  void fieldTimeStepped(float time_step);
  void fieldLeftPassed();
  void fieldRightPassed();
  void fieldTopCollided(const Rectangle& colliding_rect);
  void fieldBottomCollided(const Rectangle& colliding_rect);

  // Effects (Paddle)
  void paddleMoved(const Rectangle& moving_rect);
  void paddleBallReturned();

  // Effects (Window)
  void windowRendering(sf::RenderTarget& render);
  void windowClosed();

private:
  void randomizeDirection();
};

#endif /*_BALL_H_*/
