#ifndef _PADDLE_H_
#define _PADDLE_H_

#include <p/eventer.h>
#include <SFML/Graphics.hpp>

// Actualizer
#include "paddleeffector.h"

// Effectors
#include "fieldeffector.h"
#include "balleffector.h"
#include "windoweffector.h"

class Paddle : public p::Eventer<Paddle,
                                 p::Act<PaddleEffector>,
                                 FieldEffector,
                                 BallEffector,
                                 WindowEffector> {
private:
  sf::RectangleShape rect; // geometry (position and size)
  unsigned int score = 0;

public:
  Paddle(float x = 400.0f, float y = 300.0f,
         float w = 10.0f, float h = 100.0f);

  // Effects (Field)
  void fieldTimeStepped(float time);

  // Effects (Ball)
  void ballMoved(const sf::RectangleShape& rect);

  // Effects (Window)
  void windowRendering(sf::RenderTarget& render);
  void windowClosed();
};

#endif /*_PADDLE_H_*/
