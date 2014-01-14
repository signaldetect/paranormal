#ifndef _WORLD_FIELDEFFECTOR_H_
#define _WORLD_FIELDEFFECTOR_H_

#include <p/effector.h>

#include "geom/movablerect.h"
#include "geom/impact.h"

class FieldEffector : public p::Effector<FieldEffector> {
public:
  p__def(fieldLeftPassed)
  p__def(fieldRightPassed)
  p__def(fieldTopCollided,
         const MovableRect& /*collided_rect*/, const Impact& /*impact*/)
  p__def(fieldBottomCollided,
         const MovableRect& /*collided_rect*/, const Impact& /*impact*/)
};

#endif /*_WORLD_FIELDEFFECTOR_H_*/
