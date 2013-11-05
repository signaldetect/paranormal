#include "game.h"

Game::Game()
{
  actualize<p__the(GameEffector::gameLaunched)>();
  play();
}

void Game::windowRendering(sf::RenderTarget& render)
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
