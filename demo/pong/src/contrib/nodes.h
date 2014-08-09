#ifndef _CONTRIB_NODES_H_
#define _CONTRIB_NODES_H_

#include <unordered_map>
#include <string>

#include "node.h"

/**
 * Nodes
 * Class definition
 *
 * Base is unordered_map composed of keys (names of nodes) that associates
 * values of bool type (if value is true then node is defined).
 */
class Nodes : private std::unordered_map<std::string, bool> {
private:
  std::unordered_map<std::string, bool>::const_iterator cursor = cend();

public:
  void append(const std::string& name, bool defined);
  void activate(const std::string& name);
  void purge();

  bool hasActive() const;

  bool active(const std::string& name, bool required = true) const;
};

#endif /*_CONTRIB_NODES_H_*/
