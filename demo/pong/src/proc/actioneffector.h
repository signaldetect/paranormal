#ifndef _PROC_ACTIONEFFECTOR_H_
#define _PROC_ACTIONEFFECTOR_H_

#include <p/effector.h>
#include <SFML/System/Vector2.hpp> // sf::Vector2u
#include <SFML/Window/Event.hpp>

class ActionEffector : public p::Effector<ActionEffector> {
public:
  p__def(actionWindowCreated)
  p__def(actionWindowResized, const sf::Vector2u& /*new_size*/)
  p__def(actionWindowClosed)
  p__def(actionActivationChanged, bool /*active*/)
  p__def(actionActivationFailed)
  p__def(actionKeyPressed, const sf::Event::KeyEvent& /*key*/)
};

#endif /*_PROC_ACTIONEFFECTOR_H_*/
