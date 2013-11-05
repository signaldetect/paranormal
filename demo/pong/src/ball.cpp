#include <cstdlib> /* srand, rand */
#include <ctime>   /* time */

#include "ball.h"

Ball::Ball(float x, float y, float w, float h)
{
  // Setups geometry (position and size)
  rect.setPosition(x, y);
  rect.setSize(sf::Vector2f(/*x=*/w, /*y=*/h));
  rect.setOrigin(/*x=*/w / 3.0f, /*y=*/h / 3.0f);
  // Setups direction
  randomizeDirection();
}

void Ball::fieldTimeStepped(float time)
{
  const float mov_time = time / 5.0f;
  //
  sf::Vector2f pos = rect.getPosition();
  pos.x += dir.x * mov_time;
  pos.y -= dir.y * mov_time;
  //
  if (pos.y >= 592.0f)
    dir.y *= -1;
  else if (pos.y <= 8.0f) {
    pos.y += 3.0f;
    dir.y *= -1;
  }
  //
  rect.setPosition(pos);
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

void Ball::draw(sf::RenderTarget& render)
{
  render.draw(rect);
}
