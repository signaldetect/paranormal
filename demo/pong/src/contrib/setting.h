#ifndef _CONTRIB_SETTING_H_
#define _CONTRIB_SETTING_H_

#include <p/eventer.h>
#include <type_traits> // std::conditional, std::is_arithmetic,
                       // std::is_unsigned
#include <limits> // std::numeric_limits
#include <string> // + std::to_string

// Actualizer
#include "settingeffector.h"

/**
 * Setting
 * Class definition
 */
class Setting : public p::Eventer<p::Act<SettingEffector>> {
private:
  //typedef void (Setting::*BoolTypeOp)() const; // pointer for safe bool idiom

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

  const std::string dataName;
  const std::string dataValue;
  bool dataDecoded = false;
/*
  struct {
    const std::string name;
    const std::string value;
    bool decoded = false;
  } data;
*/

public:
  Setting(const std::string& name);
  Setting(const std::string& name, const std::string& value);

  template <class t_Dest>
  Setting(const std::string& name, const std::string& value,
          t_Dest& dest,
          t_Dest lim_min = NumLim<t_Dest>::min,
          t_Dest lim_max = NumLim<t_Dest>::max);

  bool exists() const;
  bool decoded() const;

  bool operator >>(std::string& dest) const;

  template <class t_Dest>
  bool operator >>(t_Dest& dest) const;

  //operator BoolTypeOp() const;

private:
  void decode(char& dest, char lim_min, char lim_max);

  void decode(unsigned char& dest,
              unsigned char lim_min, unsigned char lim_max);

  template <class t_Dest>
  void decode(t_Dest& dest, t_Dest lim_min, t_Dest lim_max);

  bool hasNegNumber(const std::string& str) const;

  template <class t_Num>
  bool inRange(t_Num number, t_Num min, t_Num max) const;

  //void boolTypeTrue() const;
};

#include "setting.tpp" // implementation of member function templates

#endif /*_CONTRIB_SETTING_H_*/
