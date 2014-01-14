#include <SFML/Graphics/Color.hpp>
#include <sstream> // std::ostringstream

#include "score.h"

Score::Score()
{
}

void Score::resourceFontLoaded(const sf::Font& font)
{
  setFont(font);
  setCharacterSize(40);
  setColor(sf::Color::White);
}

void Score::resourceConfigLoading(const ConfigNode& node)
{
  if (node.is("score")) {
    // Initializes the position
    node["x"] >> pos.x;
    node["y"] >> pos.y;
  }
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
