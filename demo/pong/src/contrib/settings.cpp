#include "settings.h"

/**
 * Settings
 * Class implementation
 */

void Settings::append(const std::string& key, const std::string& value)
{
  emplace(key, value);
}

void Settings::purge()
{
  // Clears all
  clear();
}

bool Settings::contains(const std::string& key) const
{
  return (count(key) > 0);
}

const Setting Settings::operator ()(const std::string& key) const
{
  return (contains(key) ? Setting(/*name=*/key, /*value=*/at(key))
                        : Setting(/*name=*/key));
}
