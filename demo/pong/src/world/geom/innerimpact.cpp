#include "innerimpact.h"

/**
 * InnerImpact
 * Class implementation
 */

/**
 * Computes the impact of the rectangle with inverse moving direction =>
 * => impact of the moving inner rectangle
 */
InnerImpact::InnerImpact(const Rect& rect, const MovableRect& moving_rect)
  : Impact(rect, MovableRect(/*geom=*/moving_rect.geom(),
                             /*moving_dir=*/-1 * moving_rect.dir()))
{
  // Penetration depth of inner rectangle
  pdepth = (horz() ? moving_rect.width() : moving_rect.height()) - pdepth;
}
