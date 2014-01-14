#ifndef _CONTRIB_SETTINGS_H_
#define _CONTRIB_SETTINGS_H_

#include <unordered_map>
#include <string>

#include "setting.h"

class Settings : public std::unordered_map<std::string, Setting> {
public:
  void append(const std::string& key, const std::string& value)
  {
    emplace(key, Setting(key, value));
  }

  bool contains(const std::string& key) const
  {
    return (count(key) > 0);
  }

  const Setting operator [](const std::string& key) const
  {
    return (contains(key) ? at(key) : Setting(key));
  }
};

#endif /*_CONTRIB_SETTINGS_H_*/
