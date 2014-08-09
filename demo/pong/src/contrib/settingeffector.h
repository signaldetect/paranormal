#ifndef _CONTRIB_SETTINGEFFECTOR_H_
#define _CONTRIB_SETTINGEFFECTOR_H_

#include <p/effector.h>
#include <string>

class SettingEffector : public p::Effector<SettingEffector> {
public:
  p__def(settingDoesNotExist, const std::string& /*name*/)
  p__def(settingDecodingFailed,
         const std::string& /*name*/, const std::string& /*message*/)
};

#endif /*_CONTRIB_SETTINGEFFECTOR_H_*/
