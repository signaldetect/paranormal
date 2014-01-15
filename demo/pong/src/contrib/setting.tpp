#include <sstream> // std::istringstream
#include <iostream> // std::cout, std::endl

/**
 * Setting
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
bool Setting::operator >>(t_Dest& dest) const
{
  return decode(dest);
}

template <class T_Type>
bool Setting::inRange(T_Type value, T_Type min, T_Type max) const
{
  return ((value >= min) && (value <= max));
}

/**
 * Relational operators for Setting
 */

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
