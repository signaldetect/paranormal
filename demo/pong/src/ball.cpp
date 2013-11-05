#include <cstdlib> /* srand, rand */
#include <ctime>   /* time */

#include "ball.h"

Ball::Ball(float x, float y, float w, float h)
  : initPos(x, y)
{
  // Setups geometry (position and size)
  initializePosition();
  rect.setSize(sf::Vector2f(/*x=*/w, /*y=*/h));
  rect.setOrigin(/*x=*/w / 2.0f, /*y=*/h / 2.0f);
  // Setups direction
  randomizeDirection();
}

void Ball::fieldTimeStepped(float time_step)
{
  const float offset = time_step / 5.0f;
  rect.move(/*offsetX=*/dir.x * offset, /*offsetY=*/-dir.y * offset);
  //
  actualize<p__the(BallEffector::ballMoved)>(rect);
}

void Ball::fieldLeftPassed()
{
  initializePosition();
  randomizeDirection();
}

void Ball::fieldRightPassed()
{
  initializePosition();
  randomizeDirection();
}

void Ball::fieldTopCollided(const sf::RectangleShape& clash_rect)
{
  if (rect.getOrigin() == clash_rect.getOrigin()) {
  }
}

void Ball::fieldBottomCollided(const sf::RectangleShape& clash_rect)
{
  if (rect.getOrigin() == clash_rect.getOrigin()) {
  }
}

void Ball::windowRendering(sf::RenderTarget& render)
{
  render.draw(rect);
}

void Ball::windowClosed()
{
}

void Ball::initializePosition()
{
  rect.setPosition(initPos);
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
  dir.x = x;
  dir.y = y;
}
