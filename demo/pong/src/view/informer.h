#ifndef _VIEW_INFORMER_H_
#define _VIEW_INFORMER_H_

#include <p/eventer.h>

#include "textfigure.h"

// Effectors
#include "../contrib/resourceeffector.h" // + sf::Font, ConfigNode
#include "../proc/timereffector.h" // + sf::Time

class Informer : public p::Eventer<p::Ext<TextFigure>,
                                   ResourceEffector,
                                   TimerEffector> {
private:
  float timeAccum = 0.0f; // time step accumulation
  unsigned int timeNum = 0; // time step number

public:
  Informer();

  // Effects (Resource)
  void resourceFontLoaded(const sf::Font& font) override;
  void resourceConfigLoading(const ConfigNode& node) override;

  // Effects (Timer)
  void timerStepped(const sf::Time& time_step) override;
};

#endif /*_VIEW_INFORMER_H_*/
