#ifndef _WORLD_FIELD_H_
#define _WORLD_FIELD_H_

#include <p/eventer.h>

#include "geom/rect.h"
#include "geom/impact.h"

// Actualizer
#include "fieldeffector.h"

// Effectors
#include "../contrib/resourceeffector.h" // + ConfigNode
#include "balleffector.h" // + MovableRect
#include "paddleeffector.h" // + MovableRect

class Field : public p::Eventer<p::Act<FieldEffector>,
                                p::Ext<Rect>,
                                ResourceEffector,
                                BallEffector,
                                PaddleEffector> {
public:
  Field();

  // Effects (Resource)
  void resourceConfigLoading(const ConfigNode& node) override;

  // Effects (Ball)
  void ballMoving(const MovableRect& moving_rect) override;

  // Effects (Paddle)
  void paddleMoving(const MovableRect& moving_rect) override;

private:
  bool detectPasses(const MovableRect& rect);
  bool detectCollisions(const MovableRect& rect);

  const Impact innerImpact(const MovableRect& moving_rect) const;
};

#endif /*_WORLD_FIELD_H_*/
