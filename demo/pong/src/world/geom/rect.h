#ifndef _WORLD_GEOM_RECT_H_
#define _WORLD_GEOM_RECT_H_

#include <SFML/Graphics/Rect.hpp> // sf::FloatRect
#include <SFML/System/Vector2.hpp> // sf::Vector2f

/**
 * Rect
 * Class definition
 *
 * Positionable rectangle
 */
class Rect : protected sf::FloatRect {
private:
  typedef sf::FloatRect Base;

public:
  Rect();
  Rect(const sf::FloatRect& geom);
  virtual ~Rect();

  const sf::FloatRect& geom() const;
  float left() const;
  float right() const;
  float top() const;
  float bottom() const;
  float width() const;
  float height() const;

protected:
  bool identical(const Rect& other) const;

  virtual void setupGeometry(float x, float y, float width, float height);

  void locate(float x, float y);

  void modifyPosition(float x, float y);
  void modifyPosition(const sf::Vector2f& pos);

  void modifySize(float width, float height);
  void modifySize(const sf::Vector2f& size);

  virtual void updatePosition();
  virtual void updateSize();
};

#endif /*_WORLD_GEOM_RECT_H_*/
