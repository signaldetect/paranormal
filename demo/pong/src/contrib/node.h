#ifndef _CONTRIB_NODE_H_
#define _CONTRIB_NODE_H_

#include <p/eventer.h>
#include <string>

// Actualizer
#include "nodeeffector.h"

/**
 * Node
 *
 * Messenger of the expected node
 */
class Node : public p::Eventer<p::Act<NodeEffector>> {
public:
  Node(const std::string& name)
  {
    actualize<p__the(NodeEffector::nodeDoesNotExist)>(name);
  }

  Node(const std::string& name, bool required)
  {
    actualize<p__the(NodeEffector::nodeExpected)>(name, required);
  }
};

#endif /*_CONTRIB_NODE_H_*/
