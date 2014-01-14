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
  // Effects (Game)
  void gamePlaying() override;
};

#endif /*_PROC_TIMER_H_*/
