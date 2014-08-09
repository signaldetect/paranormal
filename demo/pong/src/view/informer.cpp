#include <iostream> // std::cout, std::endl
#include <string> // std::to_string

#include "informer.h"

void Informer::configOpeningFailed(const std::string& filename)
{
  std::cout << "Opening the configuration file '" << filename << "' failed"
            << std::endl;
}

void Informer::configParsingFailed(const std::string& filename, size_t row_num,
                                   const std::string& message)
{
  std::cout << "Parsing the configuration file '" << filename
            << "' failed on row " + std::to_string(row_num) + ": " << message
            << std::endl;
}

void Informer::nodeDoesNotExist(const std::string& name)
{
  std::cout << "Node '" << name << "' doesn't exist" << std::endl;
}

void Informer::settingDoesNotExist(const std::string& name)
{
  std::cout << "Setting '" << name << "' doesn't exist" << std::endl;
}

void Informer::settingDecodingFailed(const std::string& name,
                                     const std::string& message)
{
  std::cout << "Decoding the setting '" << name << "' failed: " << message
            << std::endl;
}

void Informer::resourceFontNotFound(const std::string& filename)
{
  std::cout << "Font file '" << filename << "' not found" << std::endl;
}
