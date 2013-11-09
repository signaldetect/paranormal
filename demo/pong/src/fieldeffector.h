#ifndef _FIELDEFFECTOR_H_
#define _FIELDEFFECTOR_H_

#include <p/effector.h>

#include "rectangle.h"

class FieldEffector : public p::Effector<FieldEffector> {
public:
  p__def(fieldTimeStepped, float /*time_step*/)
  p__def(fieldLeftPassed)
  p__def(fieldRightPassed)
  p__def(fieldTopCollided, const Rectangle& /*colliding_rect*/)
  p__def(fieldBottomCollided, const Rectangle& /*colliding_rect*/)
};

#endif /*_FIELDEFFECTOR_H_*/
