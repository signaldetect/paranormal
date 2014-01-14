#include <SFML/Graphics/Color.hpp>
#include <cmath> // round
#include <sstream> // std::ostringstream

#include "informer.h"

Informer::Informer()
{
}

void Informer::resourceFontLoaded(const sf::Font& font)
{
  setFont(font);
  setCharacterSize(16);
  setColor(sf::Color::Red);
}

void Informer::resourceConfigLoading(const ConfigNode& node)
{
  if (node.is("informer")) {
    float x, y;
    if ((node["x"] >> x) && (node["y"] >> y)) {
      // Initializes the position
      setPosition(x, y);
    }
  }
}

void Informer::timerStepped(const sf::Time& time_step)
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
