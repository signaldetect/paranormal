#ifndef _PADDLEEFFECTOR_H_
#define _PADDLEEFFECTOR_H_

#include <p/effector.h>
#include <SFML/Graphics/RectangleShape.hpp>

class PaddleEffector : public p::Effector<PaddleEffector> {
  p__effects {
    p__(paddleMoved, const sf::RectangleShape& rect);
  }
};

#endif /*_PADDLEEFFECTOR_H_*/
