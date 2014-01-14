#include "paddle.h"

#include "geom/rect.h"

Paddle::Paddle(const std::string& unique_mark)
  : mark(unique_mark)
{
}

void Paddle::resourceConfigLoading(const ConfigNode& node)
{
  if (node.is("paddle" + mark)) {
    // Geometry
    float x, y, width, height;
    if ((node["x"] >> x) && (node["y"] >> y) &&
        (node["width"] >> width) && (node["height"] >> height)) {
      // Initializes the position and size
      setupGeometry(x, y, width, height);
    }
    // Control
    int key_up, key_down;
    if ((node["keyUp"] >> key_up) && (node["keyDown"] >> key_down)) {
      // Setups control keys
      keyUp = static_cast<sf::Keyboard::Key>(key_up);
      keyDown = static_cast<sf::Keyboard::Key>(key_down);
    }
  }
}

void Paddle::timerStepped(const sf::Time& time_step)
{
  const bool up_pressed = sf::Keyboard::isKeyPressed(keyUp);
  const bool down_pressed = sf::Keyboard::isKeyPressed(keyDown);
  //
  if (up_pressed || down_pressed) {
    modifyDirVert(/*dir_y=*/up_pressed ? -1 : 1);
    //
    const float offset = 0.3f * (float)time_step.asMilliseconds();
    if (offset > 0.0f) {
      makeMove(/*offset_x=*/0.0f, /*offset_y=*/offset);
      actualize<p__the(PaddleEffector::paddleMoving)>(/*moving_rect=*/*this);
      completeMove();
    }
  }
}

void Paddle::fieldTopCollided(const MovableRect& collided_rect,
                              const Impact& impact)
{
  if (identical(collided_rect)) {
    // Corrects the position
    makeMove(/*offset=*/-impact.depth());
  }
}

void Paddle::fieldBottomCollided(const MovableRect& collided_rect,
                                 const Impact& impact)
{
  if (identical(collided_rect)) {
    // Corrects the position
    makeMove(/*offset=*/-impact.depth());
  }
}

void Paddle::ballMoving(const MovableRect& moving_rect)
{
  // Detects collision
  if (intersects(moving_rect)) {
    // Hitting the ball back
    const Rect& rect = static_cast<const Rect&>(*this);
    actualize<p__the(PaddleEffector::paddleBallReturned)>
             (/*impact=*/Impact(rect, moving_rect));
  }
}

void Paddle::gameStarted()
{
  // Locates in the initial position
  resetPosition();
}
