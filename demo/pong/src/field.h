#ifndef _FIELD_H_
#define _FIELD_H_

#include <p/eventer.h>
#include <SFML/System/Clock.hpp>

// Actualizer
#include "fieldeffector.h"

// Effectors
#include "gameeffector.h"

class Field : public p::Eventer<Field,
                                p::Act<FieldEffector>,
                                GameEffector> {
private:
  sf::Clock clock;

public:
  Field();

  // Effects (Game)
  void gameLaunched();
  void gamePlaying();

private:
  void timeStep();
};

#endif /*_FIELD_H_*/
