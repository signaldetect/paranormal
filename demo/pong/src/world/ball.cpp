#include <cstdlib> // srand, rand
#include <ctime> // time

#include "ball.h"

#include "geom/rect.h"

void Ball::configNodeParsed(const Nodes& nodes, const Settings& settings)
{
  if (nodes.active("ball")) {
    float x, y, width, height;
    if (settings("x", "y", "width", "height") >> x >> y >> width >> height) {
      // Initializes the position and size
      setupGeometry(x, y, width, height);
    }
  }
}

void Ball::timerStepped(const sf::Time& time_step)
{
  makeMove(/*offset=*/0.2f * (float)time_step.asMilliseconds());
  actualize<p__the(BallEffector::ballMoving)>(/*moving_rect=*/*this);
  completeMove();
}

void Ball::fieldLeftPassed()
{
  initialize();
}

void Ball::fieldRightPassed()
{
  initialize();
}

void Ball::fieldTopCollided(const MovableRect& collided_rect,
                            const Impact& impact)
{
  if (identical(collided_rect)) {
    // Corrects the position
    makeMove(/*offset=*/-impact.depth());
    // Changes the direction
    invertDirVert();
  }
}

void Ball::fieldBottomCollided(const MovableRect& collided_rect,
                               const Impact& impact)
{
  if (identical(collided_rect)) {
    // Corrects the position
    makeMove(/*offset=*/-impact.depth());
    // Changes the direction
    invertDirVert();
  }
}

void Ball::paddleMoving(const MovableRect& moving_rect)
{
  // Detects collision
  if (intersects(moving_rect)) {
    // Makes impulse
    const Rect& rect = static_cast<const Rect&>(*this);
    const Impact impact(rect, moving_rect);
    // Changes the direction as a result of the horizontal impact
    if (impact.horz()) {
      const int dir_x = moving_rect.dirHorz();
      if (dirHorz() != dir_x) {
        modifyDirHorz(dir_x);
        //randomizeDirVert();
      }
    }
    // Changes the direction as a result of the vertical impact
    if (impact.vert()) {
      const int dir_y = moving_rect.dirVert();
      if (dirVert() != dir_y) {
        //randomizeDirHorz();
        modifyDirVert(dir_y);
      }
    }
    // Corrects the position
    makeMove(/*offset=*/impact.depth());
  }
}

void Ball::paddleBallReturned(const Impact& impact)
{
  // Corrects the position
  makeMove(/*offset=*/-impact.depth());
  // Changes the direction
  if (impact.horz()) {
    invertDirHorz();
    //randomizeDirVert();
  }
  if (impact.vert()) {
    //randomizeDirHorz();
    invertDirVert();
  }
}

void Ball::gameStarted()
{
  initialize();
}

void Ball::initialize()
{
  // Locates in the initial position
  resetPosition();
  // Initializes the direction
  randomizeDir();
}

/**
 * Randomizes the moving direction
 */
void Ball::randomizeDir()
{
  srand(time(nullptr)); // initialize random seed
  randomizeDirHorz();
  randomizeDirVert();
}

/**
 * Randomizes the moving direction by X coordinate (horizontal)
 */
void Ball::randomizeDirHorz()
{
  // Generates random x from the set [-1, 1]
  modifyDirHorz((rand() % 2) ? -1 : 1);
}

/**
 * Randomizes the moving direction by Y coordinate (vertical)
 */
void Ball::randomizeDirVert()
{
  // Generates random y from the set [-1, 0, 1]
  modifyDirVert(rand() % 3 - 1);
}
