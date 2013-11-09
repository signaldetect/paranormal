#ifndef _FIELD_H_
#define _FIELD_H_

#include <p/eventer.h>
#include <SFML/System/Clock.hpp>
#include <SFML/System/Vector2.hpp> /* sf::Vector2f */
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Text.hpp>

#include "rectangle.h"

// Actualizer
#include "fieldeffector.h"

// Effectors
#include "gameeffector.h"
#include "balleffector.h"
#include "paddleeffector.h"
#include "windoweffector.h"

class Field : public p::Eventer<p::Act<FieldEffector>,
                                p::Ext<Rectangle>,
                                GameEffector,
                                BallEffector,
                                PaddleEffector,
                                WindowEffector> {
private:
  sf::Clock timer;

  float fps = 0.0f;
  float time = 0.0f;
  unsigned int counter = 0;

  sf::Font font;
  sf::Text infoFPS;

public:
  Field(const sf::Vector2f& pos, const sf::Vector2f& size);

  // Effects (Game)
  void gameLaunched();
  void gamePlaying();

  // Effects (Ball)
  void ballMoved(const Rectangle& moving_rect);

  // Effects (Paddle)
  void paddleMoved(const Rectangle& moving_rect);
  void paddleBallReturned();

  // Effects (Window)
  void windowRendering(sf::RenderTarget& render);
  void windowClosed();

private:
  bool detectPasses(const Rectangle& rect);
  bool detectCollisions(const Rectangle& rect);
};

#endif /*_FIELD_H_*/
