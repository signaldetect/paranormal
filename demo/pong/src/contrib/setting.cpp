#include <iostream> // std::cout, std::endl
#include <sstream> // std::istringstream

#include "setting.h"

/**
 * Setting
 * Class implementation
 */

Setting::Setting()
  : defined(false)
{
}

Setting::Setting(const std::string& key)
  : defined(false), dataKey(key)
{
}

Setting::Setting(const std::string& key, const std::string& value)
  : defined(true), dataKey(key), dataVal(value)
{
}

const std::string& Setting::key() const
{
  return dataKey;
}

const std::string& Setting::value() const
{
  return dataVal;
}

bool Setting::equals(const Setting& other) const
{
  return ((other.defined == defined) &&
          (other.dataKey == dataKey) && (other.dataVal == dataVal));
}

bool Setting::exists() const
{
  if (defined)
    return true;
  // Otherwise => setting doesn't exist
  std::cout << "Setting '" << dataKey << "' doesn't exist" << std::endl;
  return false;
}

/**
 * Setting value to string transfer
 */
bool Setting::decode(std::string& dest) const
{
  if (exists()) {
    dest = dataVal; // setting value --> dest
    return true;
  }
  // Otherwise => setting doesn't exist
  return false;
}

/**
 * Setting value to char (as a number) converter
 */
bool Setting::decode(char& dest, char lim_min, char lim_max) const
{
  short number;
  if (decode(/*dest=*/number,
             static_cast<short>(lim_min), static_cast<short>(lim_max))) {
    dest = static_cast<char>(number);
    return true;
  }
  // Otherwise => setting doesn't exist or conversion error occurred
  return false;
}

/**
 * Setting value to unsigned char (as a number) converter
 */
bool Setting::decode(unsigned char& dest,
                     unsigned char lim_min, unsigned char lim_max) const
{
  typedef unsigned short ushort;
  ushort number;
  if (decode(/*dest=*/number,
             static_cast<ushort>(lim_min), static_cast<ushort>(lim_max))) {
    dest = static_cast<unsigned char>(number);
    return true;
  }
  // Otherwise => setting doesn't exist or conversion error occurred
  return false;
}

/**
 * Safe bool idiom
 */
Setting::operator BoolTypeOp() const
{
  return (exists() ? &Setting::boolTypeTrue : nullptr);
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

/**
 * Method for safe bool idiom
 */
void Setting::boolTypeTrue() const
{
}
