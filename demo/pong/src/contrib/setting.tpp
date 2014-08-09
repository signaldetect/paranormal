#include <sstream> // std::istringstream

/**
 * Setting
 * Implementation of member function templates
 */

template <class t_Dest>
Setting::Setting(const std::string& name, const std::string& value,
                 t_Dest& dest, t_Dest lim_min, t_Dest lim_max)
  : Setting(name, value)
{
  decode(dest, lim_min, lim_max);
}

template <class t_Dest>
bool Setting::operator >>(t_Dest& dest) const
{
  if (exists()) {
    // Decodes the setting value
    return Setting(dataName, dataValue, dest).decoded();
  }
  // Otherwise => setting doesn't exist
  return false;
}

/**
 * Setting value to destination type (t_Dest) converter
 * Note: C-strings and other non-arithmetic types can't be decoded
 */
template <class t_Dest>
void Setting::decode(t_Dest& dest, t_Dest lim_min, t_Dest lim_max)
{
  std::istringstream stream(/*str=*/dataValue);
  t_Dest number;
  // Setting value --> number
  if ((stream >> number) && stream.eof() &&
      !(std::is_unsigned<t_Dest>::value && hasNegNumber(/*str=*/dataValue)) &&
      inRange(/*value=*/number, lim_min, lim_max)) {
    dest = number;
    dataDecoded = true;
  }
  else {
    // Decoding error occurred
    actualize<p__the(SettingEffector::settingDecodingFailed)>
             (dataName, "Value must be a number in the range from " +
                        std::to_string(lim_min) + " to " +
                        std::to_string(lim_max));
    dataDecoded = false;
  }
}

template <class t_Num>
bool Setting::inRange(t_Num number, t_Num min, t_Num max) const
{
  return ((number >= min) && (number <= max));
}

/**
 * Relational operators for Setting
 */

/*
template <class t_Other>
bool operator ==(const Setting& left, const t_Other& right)
{
  return left.equals(right);
}

template <class t_Other>
bool operator !=(const Setting& left, const t_Other& right)
{
  return !left.equals(right);
}

template <class t_Other>
bool operator =(const t_Other& left, const Setting& right)
{
  return left.equals(right);
}
*/
