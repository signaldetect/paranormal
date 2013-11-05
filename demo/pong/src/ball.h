#ifndef _BALL_H_
#define _BALL_H_

#include <p/eventer.h>
#include <SFML/Graphics.hpp>

// Effectors
#include "fieldeffector.h"

class Ball : public p::Eventer<Ball, FieldEffector> {
private:
  sf::RectangleShape rect; // geometry (position and size)
  sf::Vector2i dir; // direction

public:
  Ball(float x = 400.0f, float y = 300.0f, float w = 15.0f, float h = 15.0f);

  // Effects (Field)
  void fieldTimeStepped(float time);

private:
  void randomizeDirection();
  void draw(sf::RenderTarget& render);
};

#endif /*_BALL_H_*/
