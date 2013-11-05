#include <SFML/Config.hpp> /* sf::Int32 */

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

void Field::timeStep()
{
  sf::Int32 time = clock.getElapsedTime().asMilliseconds();
  clock.restart();
  //
  actualize<p__the(FieldEffector::fieldTimeStepped)>((float)time);
}
