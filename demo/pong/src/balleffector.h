#ifndef _BALLEFFECTOR_H_
#define _BALLEFFECTOR_H_

#include <p/effector.h>
#include <SFML/Graphics/RectangleShape.hpp>

class BallEffector : public p::Effector<BallEffector> {
  p__effects {
    p__(ballMoved, const sf::RectangleShape& rect);
  }
};

#endif /*_BALLEFFECTOR_H_*/
