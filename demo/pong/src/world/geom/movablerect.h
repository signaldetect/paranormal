#ifndef _WORLD_GEOM_MOVABLERECT_H_
#define _WORLD_GEOM_MOVABLERECT_H_

#include <SFML/System/Vector2.hpp> // sf::Vector2i, sf::Vector2f

#include "rect.h"

/**
 * MovableRect
 * Class definition
 *
 * Movable rectangle
 */
class MovableRect : public Rect, private sf::Vector2i {
private:
  sf::Vector2f initial; // initial position

public:
  MovableRect();
  MovableRect(const sf::FloatRect& geom, const sf::Vector2i& moving_dir);

  const sf::Vector2i& dir() const;
  int dirHorz() const;
  int dirVert() const;

protected:
  void setupGeometry(float x, float y, float width, float height) override;

  void makeMove(float offset_x, float offset_y);
  void makeMove(float offset);
  void makeMove(const sf::Vector2f& offset);
  void completeMove();

  void resetPosition();

  void modifyDir(int dir_x, int dir_y);
  void modifyDirHorz(int dir_x);
  void modifyDirVert(int dir_y);

  void invertDir();
  void invertDirHorz();
  void invertDirVert();
};

#endif /*_WORLD_GEOM_MOVABLERECT_H_*/
