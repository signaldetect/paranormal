#ifndef _CONTRIB_RESOURCE_H_
#define _CONTRIB_RESOURCE_H_

#include <p/eventer.h>
#include <SFML/Graphics/Font.hpp>

// Actualizer
#include "resourceeffector.h"

// Effectors
#include "../gameeffector.h"

class Resource : public p::Eventer<p::Act<ResourceEffector>,
                                   GameEffector> {
private:
  sf::Font font;

public:
  // Effects (Game)
  void gameLaunched() override;

private:
  void loadFont();
  void loadConfig();
};

#endif /*_CONTRIB_RESOURCE_H_*/
