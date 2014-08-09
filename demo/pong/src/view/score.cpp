#include <SFML/Graphics/Color.hpp>
#include <sstream> // std::ostringstream

#include "score.h"

void Score::configNodeParsed(const Nodes& nodes, const Settings& settings)
{
  if (nodes.active("score")) {
    // Initializes the position
    settings("x", "y") >> pos.x >> pos.y;
  }
}

void Score::resourceFontLoaded(const sf::Font& font)
{
  setFont(font);
  setCharacterSize(40);
  setColor(sf::Color::White);
}

void Score::fieldLeftPassed()
{
  ++scorerLeft;
  update();
}

void Score::fieldRightPassed()
{
  ++scorerRight;
  update();
}

void Score::gameStarted()
{
  scorerLeft = 0;
  scorerRight = 0;
  // Initializes the text
  update();
}

void Score::update()
{
  std::ostringstream stream;
  // Left part of the string
  stream << scorerLeft << " ";
  setString(stream.str()); // update the bounding rectangle
   // Relative position (X coordinate) of the separator ':'
  const float sep_x = getLocalBounds().width;
  // Left + right parts of the string
  stream << ": " << scorerRight;
  setString(stream.str());
  // Centers the text relative to the separator ':'
  setPosition(pos.x - sep_x, pos.y);
}
