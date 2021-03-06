#ifndef _VIEW_INDICATOR_H_
#define _VIEW_INDICATOR_H_

#include <p/eventer.h>

#include "textfigure.h"

// Effectors
#include "../contrib/configeffector.h" // + Nodes, Settings
#include "../contrib/resourceeffector.h" // + sf::Font
#include "../proc/timereffector.h" // + sf::Time

class Indicator : public p::Eventer<p::Ext<TextFigure>,
                                    ConfigEffector,
                                    ResourceEffector,
                                    TimerEffector> {
private:
  float timeAccum = 0.0f; // time step accumulation
  unsigned int timeNum = 0; // time step number

public:
  // Effects

  // * Config
  p__inc(configNodeParsed, const Nodes& nodes, const Settings& settings)

  // * Resource
  p__inc(resourceFontLoaded, const sf::Font& font)

  // * Timer
  p__inc(timerStepped, const sf::Time& time_step)
};

#endif /*_VIEW_INDICATOR_H_*/
