#ifndef _CONTRIB_NODEEFFECTOR_H_
#define _CONTRIB_NODEEFFECTOR_H_

#include <p/effector.h>
#include <string>

class NodeEffector : public p::Effector<NodeEffector> {
public:
  p__def(nodeExpected, const std::string& /*name*/, bool /*required*/)
  p__def(nodeDoesNotExist, const std::string& /*name*/)
};

#endif /*_CONTRIB_NODEEFFECTOR_H_*/
