#ifndef _CONTRIB_SETTING_H_
#define _CONTRIB_SETTING_H_

#include <iostream> // std::cout, std::endl

#include <type_traits> // std::conditional, std::is_arithmetic,
                       // std::is_unsigned
#include <limits> // std::numeric_limits
#include <string>
#include <sstream> // std::istringstream

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

private:
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

/**
 * Implementation of member function templates
 */

/**
 * Setting value to destination type (t_Dest) converter
 * Note: C-strings and other non-arithmetic types can't be decoded
 */
template <class t_Dest>
bool Setting::decode(t_Dest& dest, t_Dest lim_min, t_Dest lim_max) const
{
  if (exists()) {
    std::istringstream stream(/*str=*/dataVal);
    t_Dest number;
    // Converting setting value --> number
    if ((stream >> number) && stream.eof() &&
        !(std::is_unsigned<t_Dest>::value && hasNegNumber(/*str=*/dataVal)) &&
        inRange(/*value=*/number, lim_min, lim_max)) {
      dest = number;
      return true;
    }
    else {
      std::cout << "Conversion error: value of the setting '" << dataKey
                << "' must be a number in the range from "
                << lim_min << " to " << lim_max << std::endl;
    }
  }
  // Otherwise => setting doesn't exist or conversion error occurred
  return false;
}

template <class t_Dest>
inline
bool Setting::operator >>(t_Dest& dest) const
{
  return decode(dest);
}

template <class T_Type>
inline
bool Setting::inRange(T_Type value, T_Type min, T_Type max) const
{
  return ((value >= min) && (value <= max));
}

/**
 * Relational operators for Setting
 */

template <class t_Other>
inline
bool operator ==(const Setting& left, const t_Other& right)
{
  return left.equals(right);
}

template <class t_Other>
inline
bool operator !=(const Setting& left, const t_Other& right)
{
  return !left.equals(right);
}

#endif /*_CONTRIB_SETTING_H_*/
