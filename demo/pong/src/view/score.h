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
  // Effects (Config)
  void configNodeParsed(const Nodes& nodes, const Settings& settings) override;

  // Effects (Resource)
  void resourceFontLoaded(const sf::Font& font) override;

  // Effects (Field)
  void fieldLeftPassed() override;
  void fieldRightPassed() override;

  // Effects (Game)
  void gameStarted() override;

private:
  void update();
};

#endif /*_VIEW_SCORE_H_*/
