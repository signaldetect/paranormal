#ifndef _WORLD_PADDLEEFFECTOR_H_
#define _WORLD_PADDLEEFFECTOR_H_

#include <p/effector.h>

#include "geom/movablerect.h"
#include "geom/impact.h"

class PaddleEffector : public p::Effector<PaddleEffector> {
public:
  p__def(paddleMoving, const MovableRect& /*moving_rect*/)
  p__def(paddleBallReturned, const Impact& /*impact*/)
};

#endif /*_WORLD_PADDLEEFFECTOR_H_*/
