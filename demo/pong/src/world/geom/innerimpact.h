#ifndef _WORLD_GEOM_INNERIMPACT_H_
#define _WORLD_GEOM_INNERIMPACT_H_

#include "impact.h" // + Rect, MovableRect

/**
 * InnerImpact
 * Class definition
 *
 * Stores contact dimensions and penetration depth of the impact of a moving
 * inner rectangle
 */
class InnerImpact : public Impact {
public:
  InnerImpact(const Rect& rect, const MovableRect& moving_rect);
};

#endif /*_WORLD_GEOM_INNERIMPACT_H_*/
