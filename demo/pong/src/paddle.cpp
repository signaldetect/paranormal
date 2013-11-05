#include "paddle.h"

Paddle::Paddle(float x, float y, float w, float h)
{
  // Setups geometry (position and size)
  rect.setPosition(x, y);
  rect.setSize(sf::Vector2f(/*x=*/w, /*y=*/h));
  rect.setOrigin(/*x=*/w / 2.0f, /*y=*/h / 2.0f);
}

void Paddle::gameLaunched()
{
}

void Paddle::gamePlaying()
{
}

void Paddle::draw(sf::RenderTarget& render)
{
  render.draw(rect);
}

void Paddle::update(float time)
{
  sf::Vector2f pos = rect.getPosition();
  //
  if (up_pressed)
    pos.y -= time * 0.3f;
  else if (down_pressed)
    pos.y += time * 0.3f;
  //
  rect.setPosition(pos);
}
