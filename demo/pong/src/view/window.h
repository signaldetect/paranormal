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
#include "../contrib/resourceeffector.h" // + ConfigNode
#include "../contrib/figureeffector.h" // + sf::Drawable
#include "../proc/actioneffector.h" // + sf::Vector2u
#include "../gameeffector.h"

class Window : public p::Eventer<p::Act<WindowEffector>,
                                 p::Ext<sf::RenderTarget>,
                                 ResourceEffector,
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
  Window();

  sf::Vector2u getSize() const override;

  // Effects (Resource)
  void resourceConfigLoading(const ConfigNode& node) override;

  // Effects (Figure)
  void figureDrawingReady(const sf::Drawable& drawable) override;

  // Effects (Action)
  void actionWindowCreated() override;
  void actionWindowResized(const sf::Vector2u& new_size) override;
  void actionActivationChanged(bool active) override;
  void actionActivationFailed() override;

  // Effects (Game)
  void gamePlaying() override;
  void gameStopped() override;

private:
  bool activate(bool active) override;
};

#endif /*_VIEW_WINDOW_H_*/
