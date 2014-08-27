#ifndef _PROC_TIMER_H_
#define _PROC_TIMER_H_

#include <p/eventer.h>
#include <SFML/System/Clock.hpp>

// Actualizer
#include "timereffector.h"

// Effectors
#include "../gameeffector.h"

class Timer : public p::Eventer<p::Act<TimerEffector>,
                                p::Ext<sf::Clock>,
                                GameEffector> {
public:
  // Effects

  // * Game
  p__inc(gamePlaying)
};

#endif /*_PROC_TIMER_H_*/
