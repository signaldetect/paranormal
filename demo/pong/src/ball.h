#ifndef _BALL_H_
#define _BALL_H_

#include <p/eventer.h>
#include <SFML/Graphics.hpp>

// Actualizer
#include "balleffector.h"

// Effectors
#include "fieldeffector.h"
#include "windoweffector.h"

class Ball : public p::Eventer<Ball,
                               p::Act<BallEffector>,
                               FieldEffector,
                               WindowEffector> {
private:
  const sf::Vector2f initPos; // initial position

  sf::RectangleShape rect; // geometry (position and size)
  sf::Vector2i dir; // direction

public:
  Ball(float x = 400.0f, float y = 300.0f, float w = 15.0f, float h = 15.0f);

  // Effects (Field)
  void fieldTimeStepped(float time_step);
  void fieldLeftPassed();
  void fieldRightPassed();
  void fieldTopCollided(const sf::RectangleShape& clash_rect);
  void fieldBottomCollided(const sf::RectangleShape& clash_rect);

  // Effects (Window)
  void windowRendering(sf::RenderTarget& render);
  void windowClosed();

private:
  void initializePosition();
  void randomizeDirection();
};

#endif /*_BALL_H_*/
