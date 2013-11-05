#ifndef _WINDOWEFFECTOR_H_
#define _WINDOWEFFECTOR_H_

#include <p/effector.h>
#include <SFML/Graphics/RenderTarget.hpp>

class WindowEffector : public p::Effector<WindowEffector> {
  p__effects {
    p__(windowRendering, sf::RenderTarget& render);
    p__(windowClosed);
  }
};

#endif /*_WINDOWEFFECTOR_H_*/
