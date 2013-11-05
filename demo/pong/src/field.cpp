#include <SFML/Config.hpp>         /* sf::Int32 */
#include <SFML/System/Vector2.hpp> /* sf::Vector2f */

#include "field.h"

Field::Field()
{
}

void Field::gameLaunched()
{
}

void Field::gamePlaying()
{
  timeStep();
}

void Field::ballMoved(const sf::RectangleShape& rect)
{
  detectPasses(rect);
  detectCollisions(rect);
}

void Field::paddleMoved(const sf::RectangleShape& rect)
{
  detectCollisions(rect);
}

void Field::timeStep()
{
  const sf::Int32 time = clock.getElapsedTime().asMilliseconds();
  clock.restart();
  //
  actualize<p__the(FieldEffector::fieldTimeStepped)>((float)time);
}

void Field::detectPasses(const sf::RectangleShape& rect)
{
  const sf::Vector2f pos = rect.getPosition();
  // Detects passes
  if (pos.x <= 30.0f) {
    // The rect passed over the left border
    actualize<p__the(FieldEffector::fieldLeftPassed)>();
  }
  else if (pos.x >= 770.0f) {
    // The rect passed over the right border
    actualize<p__the(FieldEffector::fieldRightPassed)>();
  }
}

void Field::detectCollisions(const sf::RectangleShape& rect)
{
  const sf::Vector2f pos = rect.getPosition();
  // Detects collisions
  if (pos.y <= 8.0f) {
    // The top border collision
    actualize<p__the(FieldEffector::fieldTopCollided)>(rect);
  }
  else if (pos.y >= 592.0f) {
    // The bottom border collision
    actualize<p__the(FieldEffector::fieldBottomCollided)>(rect);
  }
}
