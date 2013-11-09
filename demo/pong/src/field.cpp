#include <sstream>         /* std::stringstream */
#include <cmath>           /* round */
#include <SFML/Config.hpp> /* sf::Int32 */
#include <SFML/Graphics/Color.hpp>
#include <SFML/System/String.hpp>

#include "field.h"

Field::Field(const sf::Vector2f& pos, const sf::Vector2f& size)
{
  // Setups position and size
  setupGeometry(pos, size);
  // Load the text font
  if (font.loadFromFile("../resrc/sansation.ttf")) {
    infoFPS.setFont(font);
    infoFPS.setCharacterSize(16);
    infoFPS.setColor(sf::Color::Red);
  }
  infoFPS.setPosition(/*x=*/50.0f, /*y=*/10.0f);
}

void Field::gameLaunched()
{
}

void Field::gamePlaying()
{
  const sf::Int32 time_step = timer.getElapsedTime().asMilliseconds();
  time += timer.getElapsedTime().asSeconds();
  timer.restart();
  // FPS
  ++counter;
  if (time >= 0.1f) {
    fps = round((float)counter / time);
    time = 0.0f;
    counter = 0;
  }
  //fps = round(1.0f / timer.getElapsedTime().asSeconds());
  //
  actualize<p__the(FieldEffector::fieldTimeStepped)>((float)time_step);
}

void Field::ballMoved(const Rectangle& moving_rect)
{
  if (!detectPasses(moving_rect))
    detectCollisions(moving_rect);
}

void Field::paddleMoved(const Rectangle& moving_rect)
{
  detectCollisions(moving_rect);
}

void Field::paddleBallReturned()
{
}

void Field::windowRendering(sf::RenderTarget& render)
{
  std::stringstream stream;
  stream << "FPS = " << fps;
  infoFPS.setString(sf::String(stream.str()));
  render.draw(/*drawable=*/infoFPS);
}

void Field::windowClosed()
{
}

bool Field::detectPasses(const Rectangle& rect)
{
  if (rect.borderLeft() <= borderLeft()) {
    // The rect passed over the left border
    actualize<p__the(FieldEffector::fieldLeftPassed)>();
  }
  else if (rect.borderRight() >= borderRight()) {
    // The rect passed over the right border
    actualize<p__the(FieldEffector::fieldRightPassed)>();
  }
  else
    return false;
  //
  return true;
}

bool Field::detectCollisions(const Rectangle& rect)
{
  if (rect.borderTop() <= borderTop()) {
    // The top border collision
    actualize<p__the(FieldEffector::fieldTopCollided)>(
      /*colliding_rect=*/rect);
  }
  else if (rect.borderBottom() >= borderBottom()) {
    // The bottom border collision
    actualize<p__the(FieldEffector::fieldBottomCollided)>(
      /*colliding_rect=*/rect);
  }
  else
    return false;
  //
  return true;
}
