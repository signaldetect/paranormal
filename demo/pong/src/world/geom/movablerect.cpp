#include "movablerect.h"

/**
 * MovableRect
 * Class implementation
 */

MovableRect::MovableRect()
{
}

MovableRect::MovableRect(const sf::FloatRect& geom,
                         const sf::Vector2i& moving_dir)
  : Rect(geom), sf::Vector2i(moving_dir)
{
}

/**
 * Moving direction
 */
const sf::Vector2i& MovableRect::dir() const
{
  return static_cast<const sf::Vector2i&>(*this);
}

/**
 * Moving direction by X coordinate (horizontal)
 */
int MovableRect::dirHorz() const
{
  return x;
}

/**
 * Moving direction by Y coordinate (vertical)
 */
int MovableRect::dirVert() const
{
  return y;
}

void MovableRect::setupGeometry(float x, float y, float width, float height)
{
  // Stores the initial position
  initial.x = x;
  initial.y = y;
  // Initializes the rect
  Rect::setupGeometry(x, y, width, height);
}

void MovableRect::makeMove(float offset_x, float offset_y)
{
  locate(/*x=*/left() + (float)x * offset_x,
         /*y=*/top() + (float)y * offset_y);
}

void MovableRect::makeMove(float offset)
{
  makeMove(offset, offset);
}

void MovableRect::makeMove(const sf::Vector2f& offset)
{
  makeMove(offset.x, offset.y);
}

void MovableRect::completeMove()
{
  updatePosition();
}

/**
 * Repositions to the initial position
 */
void MovableRect::resetPosition()
{
  modifyPosition(initial);
}

/**
 * Changes the moving direction
 */
void MovableRect::modifyDir(int dir_x, int dir_y)
{
  modifyDirHorz(dir_x);
  modifyDirVert(dir_y);
}

/**
 * Changes the moving direction by X coordinate (horizontal)
 */
void MovableRect::modifyDirHorz(int dir_x)
{
  x = dir_x;
}

/**
 * Changes the moving direction by Y coordinate (vertical)
 */
void MovableRect::modifyDirVert(int dir_y)
{
  y = dir_y;
}

/**
 * Inverts the moving direction
 */
void MovableRect::invertDir()
{
  invertDirHorz();
  invertDirVert();
}

/**
 * Inverts the moving direction by X coordinate (horizontal)
 */
void MovableRect::invertDirHorz()
{
  x *= -1;
}

/**
 * Inverts the moving direction by Y coordinate (vertical)
 */
void MovableRect::invertDirVert()
{
  y *= -1;
}
