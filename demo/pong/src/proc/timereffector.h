#ifndef _PROC_TIMEREFFECTOR_H_
#define _PROC_TIMEREFFECTOR_H_

#include <p/effector.h>
#include <SFML/System/Time.hpp>

class TimerEffector : public p::Effector<TimerEffector> {
public:
  p__def(timerStepped, const sf::Time& /*time_step*/)
};

#endif /*_PROC_TIMEREFFECTOR_H_*/
