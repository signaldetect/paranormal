#ifndef _VIEW_SCORE_H_
#define _VIEW_SCORE_H_

#include <p/eventer.h>
#include <SFML/System/Vector2.hpp> // sf::Vector2f

#include "textfigure.h"

// Effectors
#include "../contrib/configeffector.h" // + Nodes, Settings
#include "../contrib/resourceeffector.h" // + sf::Font
#include "../world/fieldeffector.h"
#include "../gameeffector.h"

class Score : public p::Eventer<p::Ext<TextFigure>,
                                ConfigEffector,
                                ResourceEffector,
                                FieldEffector,
                                GameEffector> {
private:
  sf::Vector2f pos; // text position

  unsigned int scorerLeft;
  unsigned int scorerRight;

public:
  // Effects

  // * Config
  p__inc(configNodeParsed, const Nodes& nodes, const Settings& settings)

  // * Resource
  p__inc(resourceFontLoaded, const sf::Font& font)

  // * Field
  p__inc(fieldLeftPassed)
  p__inc(fieldRightPassed)

  // * Game
  p__inc(gameStarted)

private:
  void update();
};

#endif /*_VIEW_SCORE_H_*/
