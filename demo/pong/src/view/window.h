#ifndef _VIEW_WINDOW_H_
#define _VIEW_WINDOW_H_

#include <p/eventer.h>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/System/Vector2.hpp> // sf::Vector2u
#include <SFML/Graphics/Drawable.hpp>
#include <list>
#include <algorithm> // std::reference_wrapper

// Actualizer
#include "windoweffector.h"

// Effectors
#include "../contrib/configeffector.h" // + Nodes, Settings
#include "../contrib/figureeffector.h" // + sf::Drawable
#include "../proc/actioneffector.h" // + sf::Vector2u
#include "../gameeffector.h"

class Window : public p::Eventer<p::Act<WindowEffector>,
                                 p::Ext<sf::RenderTarget>,
                                 ConfigEffector,
                                 FigureEffector,
                                 ActionEffector,
                                 GameEffector> {
private:
  enum State {UNDEFINED, ACTIVATED, DEACTIVATED, FAILED};
  State state = UNDEFINED;

  sf::Vector2u size;

  typedef std::list<std::reference_wrapper<const sf::Drawable>> Drawables;
  Drawables drawables;

public:
  sf::Vector2u getSize() const override;

  // Effects

  // * Config
  p__inc(configNodeParsed, const Nodes& nodes, const Settings& settings)

  // * Figure
  p__inc(figureDrawingReady, const sf::Drawable& drawable)

  // * Action
  p__inc(actionWindowCreated)
  p__inc(actionWindowResized, const sf::Vector2u& new_size)
  p__inc(actionActivationChanged, bool active)
  p__inc(actionActivationFailed)

  // * Game
  p__inc(gamePlaying)
  p__inc(gameStopped)

private:
  bool activate(bool active) override;
};

#endif /*_VIEW_WINDOW_H_*/
