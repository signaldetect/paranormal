#ifndef _FIELDEFFECTOR_H_
#define _FIELDEFFECTOR_H_

#include <p/effector.h>
#include <SFML/Graphics/RectangleShape.hpp>

class FieldEffector : public p::Effector<FieldEffector> {
  p__effects {
    p__(fieldTimeStepped, float time);
    p__(fieldLeftPassed);
    p__(fieldRightPassed);
    p__(fieldTopCollided, const sf::RectangleShape& clash_rect);
    p__(fieldBottomCollided, const sf::RectangleShape& clash_rect);
  }
};

#endif /*_FIELDEFFECTOR_H_*/
