#ifndef _WORLD_BALLEFFECTOR_H_
#define _WORLD_BALLEFFECTOR_H_

#include <p/effector.h>

#include "geom/movablerect.h"

class BallEffector : public p::Effector<BallEffector> {
public:
  p__def(ballMoving, const MovableRect& /*moving_rect*/)
};

#endif /*_WORLD_BALLEFFECTOR_H_*/
