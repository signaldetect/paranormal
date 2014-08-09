#ifndef _CONTRIB_SETTINGS_H_
#define _CONTRIB_SETTINGS_H_

#include <unordered_map>
#include <string>

#include "setting.h"
#include "settingseq.h"

/**
 * Settings
 * Class definition
 *
 * Settings of current node
 */
class Settings : private std::unordered_map<std::string, std::string> {
public:
  void append(const std::string& key, const std::string& value);
  void purge();

  bool contains(const std::string& key) const;

  const Setting operator ()(const std::string& key) const;

  template <class ...vt_RestKeys, size_t t_N = sizeof...(vt_RestKeys) + 1>
  const SettingSeq<t_N> operator ()(const std::string& first_key,
                                    vt_RestKeys... rest_keys) const;
};

template <class ...vt_RestKeys, size_t t_N>
const SettingSeq<t_N> Settings::operator ()(const std::string& first_key,
                                            vt_RestKeys... rest_keys) const
{
  return SettingSeq<t_N>(/*settings=*/*this, first_key, rest_keys...);
}

#endif /*_CONTRIB_SETTINGS_H_*/
