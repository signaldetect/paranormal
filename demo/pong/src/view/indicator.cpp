#include <SFML/Graphics/Color.hpp>
#include <cmath> // round
#include <sstream> // std::ostringstream

#include "indicator.h"

void Indicator::configNodeParsed(const Nodes& nodes, const Settings& settings)
{
  if (nodes.active("indicator")) {
    float x, y;
    if (settings("x", "y") >> x >> y) {
      // Initializes the position
      setPosition(x, y);
    }
  }
}

void Indicator::resourceFontLoaded(const sf::Font& font)
{
  setFont(font);
  setCharacterSize(16);
  setColor(sf::Color::Red);
}

void Indicator::timerStepped(const sf::Time& time_step)
{
  timeAccum += time_step.asSeconds();
  ++timeNum;
  // FPS calculations
  if (timeAccum >= 0.1f) {
    const float fps = round((float)timeNum / timeAccum);
    timeAccum = 0.0f;
    timeNum = 0;
    // Updates the text
    std::ostringstream stream;
    stream << "FPS = " << fps;
    setString(stream.str());
  }
}
