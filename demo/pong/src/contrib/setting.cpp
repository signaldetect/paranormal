#include <sstream> // std::istringstream

#include "setting.h"

/**
 * Setting
 * Class implementation
 */

Setting::Setting(const std::string& name)
  : dataName(name)
{
  actualize<p__the(SettingEffector::settingDoesNotExist)>(name);
}

Setting::Setting(const std::string& name, const std::string& value)
  : dataName(name), dataValue(value)
{
}

bool Setting::exists() const
{
  return !dataValue.empty();
}

bool Setting::decoded() const
{
  return dataDecoded;
}

bool Setting::operator >>(std::string& dest) const
{
  if (exists()) {
    dest = dataValue;
    return true;
  }
  // Otherwise => setting doesn't exist
  return false;
}

/**
 * Setting value to char (as a number) converter
 */
void Setting::decode(char& dest, char lim_min, char lim_max)
{
  short number;
  decode(/*dest=*/number,
         static_cast<short>(lim_min), static_cast<short>(lim_max));
  if (decoded())
    dest = static_cast<char>(number);
}

/**
 * Setting value to unsigned char (as a number) converter
 */
void Setting::decode(unsigned char& dest,
                     unsigned char lim_min, unsigned char lim_max)
{
  typedef unsigned short ushort;
  ushort number;
  decode(/*dest=*/number,
         static_cast<ushort>(lim_min), static_cast<ushort>(lim_max));
  if (decoded())
    dest = static_cast<unsigned char>(number);
}

bool Setting::hasNegNumber(const std::string& str) const
{
  // Parses the string value and tries to extract it into the signed test
  // variable of short int type
  std::istringstream stream(str);
  short test;
  stream >> test;
  // If stream and eofbit => test value is in the range of short int
  // If !stream (failbit) and eofbit =>
  // => test value is out the range of short int and
  //    test == max of short int, if value is positive, or
  //            min of short int, if value is negative
  if (stream.eof() && (test < 0)) {
    // Extracted a negative number
    return true;
  }
  // Otherwise => extracted a positive number or conversion error occurred
  return false;
}

/*
bool Setting::equals(const Setting& other) const
{
  return ((other.defined == defined) &&
          (other.dataKey == dataKey) && (other.dataVal == dataVal));
}
*/

/**
 * Safe bool idiom
 */
/*
Setting::operator BoolTypeOp() const
{
  return (exists() ? &Setting::boolTypeTrue : nullptr);
}
*/

/**
 * Method for safe bool idiom
 */
/*
void Setting::boolTypeTrue() const
{
}
*/
