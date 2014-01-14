#ifndef _CONTRIB_CONFIGNODE_H_
#define _CONTRIB_CONFIGNODE_H_

#include <string>

#include "settings.h"

class ConfigNode : public Settings {
private:
  const std::string name;

public:
  ConfigNode(const std::string& node_name)
    : name(node_name)
  {
  }

  bool is(const std::string& node_name) const
  {
    return (node_name == name);
  }
};

#endif /*_CONTRIB_CONFIGNODE_H_*/
