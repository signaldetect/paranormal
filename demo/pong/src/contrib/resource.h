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
  bool loading = true;

  sf::Font font;

public:
  // Effects

  // * Game
  p__inc(gameLaunched)
  p__inc(gameStopped)

private:
  void load();
  void fail();
};

#endif /*_CONTRIB_RESOURCE_H_*/
