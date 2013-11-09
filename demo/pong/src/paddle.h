#ifndef _PADDLE_H_
#define _PADDLE_H_

#include <p/eventer.h>
#include <SFML/System/Vector2.hpp> /* sf::Vector2f */
#include <SFML/Graphics/RenderTarget.hpp>

#include "rectangle.h"

// Actualizer
#include "paddleeffector.h"

// Effectors
#include "fieldeffector.h"
#include "balleffector.h"
#include "windoweffector.h"

class Paddle : public p::Eventer<p::Act<PaddleEffector>,
                                 p::Ext<Rectangle>,
                                 FieldEffector,
                                 BallEffector,
                                 WindowEffector> {
private:
  float offset = 0.0f;
  //unsigned int score = 0;

public:
  Paddle(const sf::Vector2f& pos, const sf::Vector2f& size);

  // Effects (Field)
  void fieldTimeStepped(float time_step);
  void fieldLeftPassed();
  void fieldRightPassed();
  void fieldTopCollided(const Rectangle& colliding_rect);
  void fieldBottomCollided(const Rectangle& colliding_rect);

  // Effects (Ball)
  void ballMoved(const Rectangle& moving_rect);

  // Effects (Window)
  void windowRendering(sf::RenderTarget& render);
  void windowClosed();

//private:
//  const sf::RectangleShape intersect(const sf::RectangleShape& other) const;
};

#endif /*_PADDLE_H_*/
