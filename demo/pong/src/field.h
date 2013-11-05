#ifndef _FIELD_H_
#define _FIELD_H_

#include <p/eventer.h>
#include <SFML/System/Clock.hpp>
#include <SFML/Graphics/RectangleShape.hpp>

// Actualizer
#include "fieldeffector.h"

// Effectors
#include "gameeffector.h"
#include "balleffector.h"
#include "paddleeffector.h"

class Field : public p::Eventer<Field,
                                p::Act<FieldEffector>,
                                GameEffector,
                                BallEffector,
                                PaddleEffector> {
private:
  sf::Clock clock;
  sf::RectangleShape border;

public:
  Field();

  // Effects (Game)
  void gameLaunched();
  void gamePlaying();

  // Effects (Ball)
  void ballMoved(const sf::RectangleShape& rect);

  // Effects (Paddle)
  void paddleMoved(const sf::RectangleShape& rect);

private:
  void timeStep();
  void detectPasses(const sf::RectangleShape& rect);
  void detectCollisions(const sf::RectangleShape& rect);
};

#endif /*_FIELD_H_*/
