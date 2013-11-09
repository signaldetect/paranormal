#ifndef _WINDOWEFFECTOR_H_
#define _WINDOWEFFECTOR_H_

#include <p/effector.h>
#include <SFML/Graphics/RenderTarget.hpp>

class WindowEffector : public p::Effector<WindowEffector> {
public:
  p__def(windowRendering, sf::RenderTarget& /*render*/)
  p__def(windowClosed)
};

#endif /*_WINDOWEFFECTOR_H_*/
