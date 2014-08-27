#ifndef _VIEW_INFORMER_H_
#define _VIEW_INFORMER_H_

#include <p/eventer.h>

// Effectors
#include "../contrib/configeffector.h" // + std::string
#include "../contrib/nodeeffector.h" // + std::string
#include "../contrib/settingeffector.h" // + std::string
#include "../contrib/resourceeffector.h" // + std::string

class Informer : public p::Eventer<ConfigEffector,
                                   NodeEffector,
                                   SettingEffector,
                                   ResourceEffector> {
public:
  // Effects

  // * Config
  p__inc(configOpeningFailed, const std::string& filename)
  p__inc(configParsingFailed,
         const std::string& filename, size_t row_num,
         const std::string& message)

  // * Node
  p__inc(nodeDoesNotExist, const std::string& name)

  // * Setting
  p__inc(settingDoesNotExist, const std::string& name)
  p__inc(settingDecodingFailed,
         const std::string& name, const std::string& message)

  // * Resource
  p__inc(resourceFontNotFound, const std::string& filename)
};

#endif /*_VIEW_INFORMER_H_*/
