#ifndef _VIEW_WINDOWEFFECTOR_H_
#define _VIEW_WINDOWEFFECTOR_H_

#include <p/effector.h>
#include <SFML/Window/VideoMode.hpp>
#include <SFML/System/String.hpp>

class WindowEffector : public p::Effector<WindowEffector> {
public:
  p__def(windowCreating,
         const sf::VideoMode& /*mode*/, const sf::String& /*title*/,
         bool /*vsync*/)
  p__def(windowActivationChanging, bool /*active*/)
};

#endif /*_VIEW_WINDOWEFFECTOR_H_*/
