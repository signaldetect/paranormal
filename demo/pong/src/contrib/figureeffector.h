#ifndef _CONTRIB_FIGUREEFFECTOR_H_
#define _CONTRIB_FIGUREEFFECTOR_H_

#include <p/effector.h>
#include <SFML/Graphics/Drawable.hpp>

class FigureEffector : public p::Effector<FigureEffector> {
public:
  p__def(figureDrawingReady, const sf::Drawable& /*drawable*/)
};

#endif /*_CONTRIB_FIGUREEFFECTOR_H_*/
