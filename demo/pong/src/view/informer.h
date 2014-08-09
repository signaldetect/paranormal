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
  // Effects (Config)
  void configOpeningFailed(const std::string& filename) override;
  void configParsingFailed(const std::string& filename, size_t row_num,
                           const std::string& message) override;

  // Effects (Node)
  void nodeDoesNotExist(const std::string& name) override;

  // Effects (Setting)
  void settingDoesNotExist(const std::string& name) override;
  void settingDecodingFailed(const std::string& name,
                             const std::string& message) override;

  // Effects (Resource)
  void resourceFontNotFound(const std::string& filename) override;
};

#endif /*_VIEW_INFORMER_H_*/
