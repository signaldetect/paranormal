#ifndef _WORLD_FIELD_H_
#define _WORLD_FIELD_H_

#include <p/eventer.h>

#include "geom/rect.h"
#include "geom/impact.h"

// Actualizer
#include "fieldeffector.h"

// Effectors
#include "../contrib/configeffector.h" // + Nodes, Settings
#include "balleffector.h" // + MovableRect
#include "paddleeffector.h" // + MovableRect

class Field : public p::Eventer<p::Act<FieldEffector>,
                                p::Ext<Rect>,
                                ConfigEffector,
                                BallEffector,
                                PaddleEffector> {
public:
  // Effects

  // * Config
  p__inc(configNodeParsed, const Nodes& nodes, const Settings& settings)

  // * Ball
  p__inc(ballMoving, const MovableRect& moving_rect)

  // * Paddle
  p__inc(paddleMoving, const MovableRect& moving_rect)

private:
  bool detectPasses(const MovableRect& rect);
  bool detectCollisions(const MovableRect& rect);

  const Impact innerImpact(const MovableRect& moving_rect) const;
};

#endif /*_WORLD_FIELD_H_*/
