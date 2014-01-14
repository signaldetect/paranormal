#ifndef _WORLD_GEOM_IMPACT_H_
#define _WORLD_GEOM_IMPACT_H_

#include <SFML/System/Vector2.hpp>

#include "rect.h"
#include "movablerect.h"

/**
 * Impact
 * Class definition
 *
 * Stores contact dimensions and penetration depth of the impact of a moving
 * rectangle
 */
class Impact {
protected:
  sf::Vector2<bool> contact; // contact dimensions
  float pdepth; // penetration depth

public:
  Impact(const Rect& rect, const MovableRect& moving_rect);

  bool horz() const;
  bool vert() const;

  float depth() const;
};

#endif /*_WORLD_GEOM_IMPACT_H_*/
