#include <SFML/System/Vector2.hpp> // sf::Vector2f

#include "movablerectfigure.h"

/**
 * MovableRectFigure
 * Class implementation
 */

void MovableRectFigure::updatePosition()
{
  shape.setPosition(/*x=*/left(), /*y=*/top());
}

void MovableRectFigure::updateSize()
{
  shape.setSize(sf::Vector2f(width(), height()));
}

const sf::Drawable& MovableRectFigure::asDrawable() const
{
  return static_cast<const sf::Drawable&>(shape);
}
