#include "rect.h"

/**
 * Rect
 * Class implementation
 */

Rect::Rect()
{
}

Rect::Rect(const sf::FloatRect& geom)
  : Base(geom)
{
}

Rect::~Rect()
{
}

const sf::FloatRect& Rect::geom() const
{
  return static_cast<const Base&>(*this);
}

float Rect::left() const
{
  return Base::left;
}

float Rect::right() const
{
  return Base::left + Base::width;
}

float Rect::top() const
{
  return Base::top;
}

float Rect::bottom() const
{
  return Base::top + Base::height;
}

float Rect::width() const
{
  return Base::width;
}

float Rect::height() const
{
  return Base::height;
}

bool Rect::identical(const Rect& other) const
{
  return (&other == this);
}

void Rect::setupGeometry(float x, float y, float width, float height)
{
  modifyPosition(x, y);
  modifySize(width, height);
}

void Rect::locate(float x, float y)
{
  Base::left = x;
  Base::top = y;
}

void Rect::modifyPosition(float x, float y)
{
  locate(x, y);
  updatePosition();
}

void Rect::modifyPosition(const sf::Vector2f& pos)
{
  modifyPosition(pos.x, pos.y);
}

void Rect::modifySize(float width, float height)
{
  Base::width = width;
  Base::height = height;
  //
  updateSize();
}

void Rect::modifySize(const sf::Vector2f& size)
{
  modifySize(/*width=*/size.x, /*height=*/size.y);
}

void Rect::updatePosition()
{
  // Nothing by default
}

void Rect::updateSize()
{
  // Nothing by default
}
