#include "paddle.h"

Paddle::Paddle(float x, float y, float w, float h)
{
  // Setups geometry (position and size)
  rect.setPosition(x, y);
  rect.setSize(sf::Vector2f(/*x=*/w, /*y=*/h));
  rect.setOrigin(/*x=*/w / 2.0f, /*y=*/h / 2.0f);
}

void Paddle::fieldTimeStepped(float time)
{
  const bool up_pressed = sf::Keyboard::isKeyPressed(sf::Keyboard::W);
  const bool down_pressed = sf::Keyboard::isKeyPressed(sf::Keyboard::S);
  //
  if (up_pressed || down_pressed) {
    sf::Vector2f pos = rect.getPosition();
    pos.y += (up_pressed ? -1.0f : 1.0f) * time * 0.3f;
    rect.setPosition(pos);
    //
    actualize<p__the(PaddleEffector::paddleMoved)>(rect);
  }
}

void Paddle::ballMoved(const sf::RectangleShape& rect)
{
  if ((pos.x <= 35.0f) &&
      (pos.y < (paddle_left_y + 58.0f)) &&
      (pos.y > (paddle_left_y - 58.0f))) {
    ball.setX(ball_x + 3.0f);
    ball.direction.x *= -1;
  }
  else if ((ball_x >= 765.0f) &&
           (ball_y < (paddle_right_y + 58.0f)) &&
           (ball_y > (paddle_right_y - 58.0f))) {
    ball.direction.x *= -1;
  }
}

void Paddle::windowRendering(sf::RenderTarget& render)
{
  render.draw(rect);
}

void Paddle::windowClosed()
{
}
