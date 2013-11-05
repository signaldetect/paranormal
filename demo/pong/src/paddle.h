#ifndef _PADDLE_H_
#define _PADDLE_H_

#include <p/eventer.h>
#include <SFML/Graphics.hpp>

// Effectors
#include "gameeffector.h"

class Paddle : public p::Eventer<Paddle, GameEffector> {
private:
  sf::RectangleShape rect; // geometry (position and size)
  unsigned int score = 0;

public:
  Paddle(float x = 400.0f, float y = 300.0f,
         float w = 10.0f, float h = 100.0f);

  // Effects (Game)
  void gameLaunched();
  void gamePlaying();

private:
  void draw(sf::RenderTarget& render);
  void update(sf::Int32 time);
};

#endif /*_PADDLE_H_*/
