#ifndef _CONTRIB_SETTINGSEQ_H_
#define _CONTRIB_SETTINGSEQ_H_

#include <array>
#include <string>

/**
 * SettingSeq
 *
 * Sequence of settings
 */

template <size_t T_N, class T_KeyIt = void>
class SettingSeq : private SettingSeq<0, T_KeyIt> {
private:
  typedef SettingSeq<0, T_KeyIt> Base;

public:
  template <class t_First, class ...vt_Rest>
  SettingSeq(t_First&& first, vt_Rest&&... rest)
    : Base(first, rest...)
  {
  }

  template <class t_Dest>
  const SettingSeq<T_N - 1, T_KeyIt> operator >>(t_Dest& dest) const
  {
    if (Base::exists() && !(Base::setting() >> dest))
      return SettingSeq<T_N - 1, T_KeyIt>(Base::dummy()); // => dummy sequence
    // Otherwise => dummy sequence continue or value --> dest is ok
    return SettingSeq<T_N - 1, T_KeyIt>(Base::next());
  }
};

template <size_t T_N>
class SettingSeq<T_N>
  : private std::array<std::string, T_N>,
    public SettingSeq<T_N, typename std::array<std::string,
                                               T_N>::const_iterator> {
private:
  typedef std::array<std::string, T_N> Keys;
  typedef SettingSeq<T_N, typename Keys::const_iterator> Base;

public:
  template <class t_Arg, class ...vt_Keys>
  SettingSeq(t_Arg&& arg, vt_Keys&&... keys)
    : Keys({keys...}), Base(arg, Keys::cbegin(), Keys::cend())
  {
  }
};

template <class T_KeyIt>
class SettingSeq<1, T_KeyIt> : private SettingSeq<0, T_KeyIt> {
private:
  typedef SettingSeq<0, T_KeyIt> Base;

public:
  template <class t_First, class ...vt_Rest>
  SettingSeq(t_First&& first, vt_Rest&&... rest)
    : Base(first, rest...)
  {
  }

  template <class t_Dest>
  bool operator >>(t_Dest& dest) const
  {
    return (Base::exists() && (Base::setting() >> dest));
  }
};

class Setting;
class Settings;

template <class T_KeyIt>
class SettingSeq<0, T_KeyIt> {
private:
  const Settings& settings;

  const struct {
    T_KeyIt it;
    T_KeyIt end;
  } key;

protected:
  SettingSeq(const Settings& settings, T_KeyIt it, T_KeyIt end)
    : settings(settings), key{it, end}
  {
  }

  SettingSeq(const SettingSeq& other)
    : settings(other.settings), key(other.key)
  {
  }

  bool exists() const
  {
    return (key.it != key.end);
  }

  const Setting setting() const
  {
    return settings(/*key=*/*key.it);
  }

  const SettingSeq next() const
  {
    return (exists() ? SettingSeq(settings, key.it + 1, key.end) : *this);
  }

  const SettingSeq dummy() const
  {
    return (exists() ? SettingSeq(settings, key.end, key.end) : *this);
  }
};

#endif /*_CONTRIB_SETTINGSEQ_H_*/
