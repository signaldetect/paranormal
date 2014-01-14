#include <iostream> // std::cout, std::endl

#include "game.h"

Game::Game()
  : paddleLeft(/*unique_mark=*/"Left"), paddleRight(/*unique_mark=*/"Right")
{
  launch(); // prepare playing
  start(); // start playing
  play(); // playing process
}

void Game::resourceErrorDetected(const std::string& message)
{
  // Terminates the game
  stop();
  // Shows the error message
  std::cout << message << std::endl;
}

void Game::actionWindowClosed()
{
  // Ends the game
  stop();
}

void Game::actionKeyPressed(const sf::Event::KeyEvent& key)
{
  if (key.code == sf::Keyboard::Space)
    start(); // restart the game
  else if (key.code == sf::Keyboard::Escape)
    stop(); // end the game
}

void Game::launch()
{
  state = LAUNCHED;
  actualize<p__the(GameEffector::gameLaunched)>();
}

void Game::start()
{
  if (state != STOPPED) {
    state = PLAYING;
    actualize<p__the(GameEffector::gameStarted)>();
  }
}

void Game::play()
{
  while (state == PLAYING)
    actualize<p__the(GameEffector::gamePlaying)>();
}

void Game::stop()
{
  if (state != STOPPED) {
    state = STOPPED;
    actualize<p__the(GameEffector::gameStopped)>();
  }
}
