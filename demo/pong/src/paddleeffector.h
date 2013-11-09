#ifndef _PADDLEEFFECTOR_H_
#define _PADDLEEFFECTOR_H_

#include <p/effector.h>

#include "rectangle.h"

class PaddleEffector : public p::Effector<PaddleEffector> {
public:
  p__def(paddleMoved, const Rectangle& /*moving_rect*/)
  p__def(paddleBallReturned)
};

#endif /*_PADDLEEFFECTOR_H_*/
