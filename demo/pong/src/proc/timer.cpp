#include <SFML/System/Time.hpp>

#include "timer.h"

void Timer::gamePlaying()
{
  const sf::Time time_step = getElapsedTime();
  restart();
  //
  actualize<p__the(TimerEffector::timerStepped)>(time_step);
}
