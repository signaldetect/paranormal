#ifndef _CONTRIB_CONFIGEFFECTOR_H_
#define _CONTRIB_CONFIGEFFECTOR_H_

#include <p/effector.h>
#include <string>

#include "nodes.h"
#include "settings.h"

class ConfigEffector : public p::Effector<ConfigEffector> {
public:
  p__def(configNodeParsed,
         const Nodes& /*nodes*/, const Settings& /*settings*/)

  p__def(configOpeningFailed, const std::string& /*filename*/)
  p__def(configParsingFailed,
         const std::string& /*filename*/, size_t /*row_num*/,
         const std::string& /*message*/)
  p__def(configCannotParsed)
};

#endif /*_CONTRIB_CONFIGEFFECTOR_H_*/
