#ifndef _CONTRIB_SETTING_H_
#define _CONTRIB_SETTING_H_

#include <type_traits> // std::conditional, std::is_arithmetic,
                       // std::is_unsigned
#include <limits> // std::numeric_limits
#include <string>

/**
 * Setting
 * Class definition
 */
class Setting {
private:
  typedef void (Setting::*BoolTypeOp)() const; // pointer for safe bool idiom

  /**
   * Number limits
   */
  template <class T_Type>
  class NumLim {
  public:
    class NotANumber; // non-arithmetic types can't be decoded

    typedef typename std::conditional<std::is_arithmetic<T_Type>::value,
                                      T_Type, NotANumber>::type NumType;

    typedef std::numeric_limits<NumType> Basis;

    static constexpr T_Type min = Basis::lowest();
    static constexpr T_Type max = Basis::max();
  };

  const bool defined;
  const std::string dataKey;
  const std::string dataVal;

public:
  Setting();
  Setting(const std::string& key);
  Setting(const std::string& key, const std::string& value);

  const std::string& key() const;
  const std::string& value() const;

  bool equals(const Setting& other) const;
  bool exists() const;

  bool decode(std::string& dest) const;

  bool decode(char& dest,
              char lim_min = NumLim<char>::min,
              char lim_max = NumLim<char>::max) const;

  bool decode(unsigned char& dest,
              unsigned char lim_min = NumLim<unsigned char>::min,
              unsigned char lim_max = NumLim<unsigned char>::max) const;

  template <class t_Dest>
  bool decode(t_Dest& dest,
              t_Dest lim_min = NumLim<t_Dest>::min,
              t_Dest lim_max = NumLim<t_Dest>::max) const;

  operator BoolTypeOp() const;

  template <class t_Dest>
  bool operator >>(t_Dest& dest) const;

private:
  bool hasNegNumber(const std::string& str) const;

  template <class T_Type>
  bool inRange(T_Type value, T_Type min, T_Type max) const;

  void boolTypeTrue() const;
};

#include "setting.tpp" // implementation of member function templates

#endif /*_CONTRIB_SETTING_H_*/
