#include "game.h"

Game::Game()
  : window(/*width=*/800, /*height=*/600, /*title=*/"Pong!"),
    field(/*pos=*/sf::Vector2f(25.0f, 0.0f),
          /*size=*/sf::Vector2f(750.0f, 600.0f)),
    ball(/*pos=*/sf::Vector2f(400.0f, 300.0f),
         /*size=*/sf::Vector2f(15.0f, 15.0f)),
    paddleLeft(/*pos=*/sf::Vector2f(30.0f, 300.0f),
               /*size=*/sf::Vector2f(10.0f, 100.0f))
{
  actualize<p__the(GameEffector::gameLaunched)>();
  play();
}

void Game::windowRendering(sf::RenderTarget& /*render*/)
{
}

void Game::windowClosed()
{
  playing = false;
}

void Game::play()
{
  playing = true;
  while (playing)
    actualize<p__the(GameEffector::gamePlaying)>();
}
