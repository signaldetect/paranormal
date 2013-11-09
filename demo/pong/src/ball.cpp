#include <cstdlib> /* srand, rand */
#include <ctime>   /* time */

#include "ball.h"

Ball::Ball(const sf::Vector2f& pos, const sf::Vector2f& size)
  : initial(pos)
{
  // Setups position and size
  setupGeometry(pos, size);
  // Setups direction
  randomizeDirection();
}

void Ball::fieldTimeStepped(float time_step)
{
  offset = 0.2f * time_step;
  move(/*offsetX=*/(float)direction.x * offset,
       /*offsetY=*/-(float)direction.y * offset);
  //
  actualize<p__the(BallEffector::ballMoved)>(/*moving_rect=*/*this);
}

void Ball::fieldLeftPassed()
{
  setPosition(initial);
  randomizeDirection();
}

void Ball::fieldRightPassed()
{
  setPosition(initial);
  randomizeDirection();
}

void Ball::fieldTopCollided(const Rectangle& colliding_rect)
{
  if (identityGeometry(colliding_rect))
    direction.y *= -1;
}

void Ball::fieldBottomCollided(const Rectangle& colliding_rect)
{
  if (identityGeometry(colliding_rect))
    direction.y *= -1;
}

void Ball::paddleMoved(const Rectangle& /*moving_rect*/)
{
}

void Ball::paddleBallReturned()
{
  move(/*offsetX=*/-(float)direction.x * offset,
       /*offsetY=*/(float)direction.y * offset);
  direction.x *= -1;
}

void Ball::windowRendering(sf::RenderTarget& render)
{
  render.draw(/*drawable=*/*this);
}

void Ball::windowClosed()
{
}

void Ball::randomizeDirection()
{
  // Initialize random seed
  srand(time(nullptr));
  // Generate random x and y from set [-1..1]
  int x = rand() % 3 - 1;
  int y = rand() % 3 - 1;
  //
  if (((x == 0) && (y == 0)) || ((x == 0) && (abs(y) == 1))) {
    x = 1;
    y = 1;
  }
  //
  direction.x = x;
  direction.y = y;
}
