#include "impact.h"

/**
 * Impact
 * Class implementation
 */

/**
 * Computes the contact dimensions and penetration depth
 */
Impact::Impact(const Rect& rect, const MovableRect& moving_rect)
{
  const int dir_x = moving_rect.dirHorz();
  const int dir_y = moving_rect.dirVert();
  // Horizontal offset of the rectangle b
  float x = 0.0f;
  if (dir_x > 0)
    x = moving_rect.right() - rect.left();
  else if (dir_x < 0)
    x = rect.right() - moving_rect.left();
  // Vertical offset of the rectangle b
  float y = x;
  if (dir_y > 0)
    y = moving_rect.bottom() - rect.top();
  else if (dir_y < 0)
    y = rect.bottom() - moving_rect.top();
  // Contact dimensions
  contact.x = ((dir_x != 0) && (x <= y));
  contact.y = ((dir_y != 0) && !contact.x);
  // Penetration depth
  pdepth = (contact.x ? x : y);
}

bool Impact::horz() const
{
  return contact.x;
}

bool Impact::vert() const
{
  return contact.y;
}

float Impact::depth() const
{
  return pdepth;
}
