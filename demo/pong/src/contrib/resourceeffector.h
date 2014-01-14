#ifndef _CONTRIB_RESOURCEEFFECTOR_H_
#define _CONTRIB_RESOURCEEFFECTOR_H_

#include <p/effector.h>
#include <SFML/Graphics/Font.hpp>
#include <string>

#include "confignode.h"

class ResourceEffector : public p::Effector<ResourceEffector> {
public:
  p__def(resourceFontLoaded, const sf::Font& /*font*/)
  p__def(resourceConfigLoading, const ConfigNode& /*node*/)
  p__def(resourceErrorDetected, const std::string& /*message*/)
};

#endif /*_CONTRIB_RESOURCEEFFECTOR_H_*/
