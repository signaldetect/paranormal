#include "field.h"

#include "geom/innerimpact.h"

Field::Field()
{
}

void Field::resourceConfigLoading(const ConfigNode& node)
{
  if (node.is("field")) {
    float x, y, width, height;
    if ((node["x"] >> x) && (node["y"] >> y) &&
        (node["width"] >> width) && (node["height"] >> height)) {
      // Initializes the position and size
      setupGeometry(x, y, width, height);
    }
  }
}

void Field::ballMoving(const MovableRect& moving_rect)
{
  if (!detectPasses(moving_rect))
    detectCollisions(moving_rect);
}

void Field::paddleMoving(const MovableRect& moving_rect)
{
  detectCollisions(moving_rect);
}

bool Field::detectPasses(const MovableRect& rect)
{
  if (rect.left() <= left()) {
    // The rect passed over the left border
    actualize<p__the(FieldEffector::fieldLeftPassed)>();
  }
  else if (rect.right() >= right()) {
    // The rect passed over the right border
    actualize<p__the(FieldEffector::fieldRightPassed)>();
  }
  else
    return false;
  //
  return true;
}

bool Field::detectCollisions(const MovableRect& rect)
{
  if (rect.top() <= top()) {
    // The top border collision
    actualize<p__the(FieldEffector::fieldTopCollided)>
             (/*collided_rect=*/rect, /*impact=*/innerImpact(rect));
  }
  else if (rect.bottom() >= bottom()) {
    // The bottom border collision
    actualize<p__the(FieldEffector::fieldBottomCollided)>
             (/*collided_rect=*/rect, /*impact=*/innerImpact(rect));
  }
  else
    return false;
  //
  return true;
}

const Impact Field::innerImpact(const MovableRect& moving_rect) const
{
  const Rect& rect = static_cast<const Rect&>(*this);
  return static_cast<const Impact>(InnerImpact(rect, moving_rect));
}
