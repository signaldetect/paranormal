#include <SFML/Window/Keyboard.hpp>

#include "paddle.h"

Paddle::Paddle(const sf::Vector2f& pos, const sf::Vector2f& size)
{
  // Setups position and size
  setupGeometry(pos, size);
}

void Paddle::fieldTimeStepped(float time_step)
{
  const bool up_pressed = sf::Keyboard::isKeyPressed(sf::Keyboard::W);
  const bool down_pressed = sf::Keyboard::isKeyPressed(sf::Keyboard::S);
  //
  if (up_pressed || down_pressed) {
    offset = 0.3f * time_step;
    move(/*offsetX=*/0.0f, /*offsetY=*/(up_pressed ? -offset : offset));
    //
    actualize<p__the(PaddleEffector::paddleMoved)>(/*moving_rect=*/*this);
  }
}

void Paddle::fieldLeftPassed()
{
}

void Paddle::fieldRightPassed()
{
}

void Paddle::fieldTopCollided(const Rectangle& colliding_rect)
{
  if (identityGeometry(colliding_rect))
    move(/*offsetX=*/0.0f, /*offsetY=*/offset);
}

void Paddle::fieldBottomCollided(const Rectangle& colliding_rect)
{
  if (identityGeometry(colliding_rect))
    move(/*offsetX=*/0.0f, /*offsetY=*/-offset);
}

void Paddle::ballMoved(const Rectangle& moving_rect)
{
  // Corners of moving_rect
  const sf::Vector2f& a = moving_rect.getPosition(); // top-left point
  const sf::Vector2f& b = a + moving_rect.getSize(); // bottom-right point
  // Detects collisions
  if (containsPoint(a) || containsPoint(b)) {
    // Hitting the ball back
    actualize<p__the(PaddleEffector::paddleBallReturned)>();
  }
  /*
  const sf::Vector2f& size = intersect(ball_rect).getSize();
  if ((size.x >= 0.0f) && (size.y >= 0.0f)) {
    // The paddle collision
  }
  */
}

void Paddle::windowRendering(sf::RenderTarget& render)
{
  render.draw(/*drawable=*/*this);
}

void Paddle::windowClosed()
{
}

//const sf::RectangleShape Paddle::intersect(const sf::RectangleShape& other) const
//{
//  // Paddle rect
//  const sf::Vector2f r1_p1 = rect.getPosition(); // top-left point
//  const sf::Vector2f r1_p2 = r1_p1 + rect.getSize(); // bottom-right point
//  // Other rect
//  const sf::Vector2f r2_p1 = other.getPosition(); // top-left point
//  const sf::Vector2f r2_p2 = r2_p1 + other.getSize(); // bottom-right point
//  // Intersect rect: top-left point
//  const sf::Vector2f r1_p1(/*x=*/std::min(std::max(r1_p1.x, r2_p1.x),
//                                          std::max(r1_p2.x, r2_p2.x)),
//                           /*y=*/std::min(std::max(r1_p1.y, r2_p1.y),
//                                          std::max(r1_p2.y, r2_p2.y)));
//  // Intersect rect: bottom-right point
//  const sf::Vector2f r1_p2(/*x=*/std::max(std::min(r1_p1.x, r2_p1.x),
//                                          std::min(r1_p2.x, r2_p2.x)),
//                           /*y=*/std::max(std::min(r1_p1.y, r2_p1.y),
//                                          std::min(r1_p2.y, r2_p2.y)));
//  // Intersect rect
//  sf::RectangleShape intersection;
//  intersection.setPosition(r1_p1);
//  intersection.setSize(r1_p2 - r1_p1);
//  return intersection;
//}
