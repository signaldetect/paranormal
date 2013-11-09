#ifndef _RECTANGLE_H_
#define _RECTANGLE_H_

#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/System/Vector2.hpp> /* sf::Vector2f */

class Rectangle : public sf::RectangleShape {
public:
  float borderLeft() const
  {
    return getPosition().x;
  }

  float borderRight() const
  {
    return getPosition().x + getSize().x;
  }

  float borderTop() const
  {
    return getPosition().y;
  }

  float borderBottom() const
  {
    return getPosition().y + getSize().y;
  }

protected:
  void setupGeometry(const sf::Vector2f& pos, const sf::Vector2f& size)
  {
    setPosition(pos);
    setSize(size);
  }

  bool identityGeometry(const sf::RectangleShape& rect) const
  {
    return ((getPosition() == rect.getPosition()) &&
            (getSize() == rect.getSize()));
  }

  /**
   * Checks if point in rectangle
   */
  bool containsPoint(const sf::Vector2f& point) const
  {
    return ((point.x >= borderLeft()) && (point.x <= borderRight()) &&
            (point.y >= borderTop()) && (point.y <= borderBottom()));
  }
};

#endif /*_RECTANGLE_H_*/
