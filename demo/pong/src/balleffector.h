#ifndef _BALLEFFECTOR_H_
#define _BALLEFFECTOR_H_

#include <p/effector.h>

#include "rectangle.h"

class BallEffector : public p::Effector<BallEffector> {
public:
  p__def(ballMoved, const Rectangle& /*moving_rect*/)
};

#endif /*_BALLEFFECTOR_H_*/
