#ifndef _WORLD_GEOM_MOVABLERECTFIGURE_H_
#define _WORLD_GEOM_MOVABLERECTFIGURE_H_

#include <SFML/Graphics/RectangleShape.hpp>

#include "movablerect.h"
#include "../../contrib/figure.h" // + sf::Drawable

/**
 * MovableRectFigure
 * Class definition
 *
 * Movable rectangle figure
 */
class MovableRectFigure : public MovableRect, private Figure {
private:
  sf::RectangleShape shape;

protected:
  void updatePosition() override;
  void updateSize() override;

private:
  const sf::Drawable& asDrawable() const override;
};

#endif /*_WORLD_GEOM_MOVABLERECTFIGURE_H_*/
