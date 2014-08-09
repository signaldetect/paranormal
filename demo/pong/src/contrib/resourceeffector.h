#ifndef _CONTRIB_RESOURCEEFFECTOR_H_
#define _CONTRIB_RESOURCEEFFECTOR_H_

#include <p/effector.h>
#include <SFML/Graphics/Font.hpp>
#include <string>

class ResourceEffector : public p::Effector<ResourceEffector> {
public:
  p__def(resourceFontLoaded, const sf::Font& /*font*/)

  p__def(resourceFontNotFound, const std::string& /*filename*/)
  p__def(resourceCannotLoaded)
};

#endif /*_CONTRIB_RESOURCEEFFECTOR_H_*/
