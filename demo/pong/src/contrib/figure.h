#ifndef _CONTRIB_FIGURE_H_
#define _CONTRIB_FIGURE_H_

#include <p/eventer.h>
#include <SFML/Graphics/Drawable.hpp>

// Actualizer
#include "figureeffector.h"

// Effectors
#include "../proc/actioneffector.h"

/**
 * Figure is a graphical object
 */
class Figure : public p::Eventer<p::Act<FigureEffector>,
                                 ActionEffector> {
public:
  // Effects (Action)
  void actionWindowCreated() override;

private:
  virtual const sf::Drawable& asDrawable() const = 0;
};

#endif /*_CONTRIB_FIGURE_H_*/
