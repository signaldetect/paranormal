#ifndef _VIEW_TEXTFIGURE_H_
#define _VIEW_TEXTFIGURE_H_

#include <SFML/Graphics/Text.hpp>

#include "../contrib/figure.h" // + sf::Drawable

class TextFigure : public sf::Text, private Figure {
private:
  const sf::Drawable& asDrawable() const override
  {
    return static_cast<const sf::Drawable&>(*this);
  }
};

#endif /*_VIEW_TEXTFIGURE_H_*/
