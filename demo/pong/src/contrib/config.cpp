#include "config.h"

/**
 * Config
 * Class implementation
 */

void Config::gameLaunched()
{
  // Parses the settings
  start();
  while (parsing)
    parse();
  stop();
}

void Config::gameStopped()
{
  // Game is terminated
  if (parsing)
    parsing = false;
}

void Config::nodeExpected(const std::string& name, bool required)
{
  nodes.append(name, /*defined=*/required);
  if (required)
    wanted.emplace(name);
}

void Config::nodeDoesNotExist(const std::string& /*name*/)
{
  fail();
}

void Config::settingDoesNotExist(const std::string& /*name*/)
{
  fail();
}

void Config::settingDecodingFailed(const std::string& /*name*/,
                                   const std::string& /*message*/)
{
  fail();
}

void Config::start()
{
  // Opens the configuration file
  if (parsing) {
    file.open(filePath);
    //
    if (!file.is_open()) {
      actualize<p__the(ConfigEffector::configOpeningFailed)>(filename());
      fail();
    }
  }
}

void Config::parse()
{
  std::string row;
  while (row.empty() && std::getline(file, row).good()) {
    ++rowNumber;
    row = trim(ignoreComment(row));
  }
  // Parsing
  if (file.good()) // => ready for row parsing
    parse(row);
  else { // => EOF or some failure
    if (file.eof()) // => last node is completing
      completeNode();
    // End of parsing
    complete();
  }
}

void Config::parse(const std::string& row)
{
  size_t sep_pos = row.find("="); // position of the key-value separator
  if (sep_pos != std::string::npos) {
    // Setting available
    extractSetting(row, sep_pos);
  }
  else if (row.back() == ':') {
    // Current node is completing (=> shifting to another node)
    // or first node is beginning
    completeNode();
    extractNodeName(row);
  }
  else
    makeError(/*message=*/"token ':' or '=' expected");
}

void Config::stop()
{
  // Closes the configuration file
  if (file.is_open())
    file.close();
}

void Config::completeNode()
{
  if (nodes.hasActive()) {
    actualize<p__the(ConfigEffector::configNodeParsed)>(nodes, settings);
    settings.purge();
  }
}

void Config::complete()
{
  parsing = false;
  // Checks whether required but not activated nodes
  for (const std::string& name : wanted)
    Node{name}; // nonexistent node
  wanted.clear();
  // Clears all data
  nodes.purge();
  settings.purge();
}

void Config::extractNodeName(const std::string& row)
{
  // Node name corresponds to the row from start to ':'
  const std::string name = rtrim(row.substr(0, row.length() - 1));
  // Validation check
  if (name.empty())
    makeError(/*message=*/"node name expected before ':' token");
  else {
    nodes.activate(name);
    wanted.erase(name); // node is activated => no longer wanted
  }
}

void Config::extractSetting(const std::string& row, size_t sep_pos)
{
  // Key corresponds to the row from start to separator '='
  const std::string key = rtrim(row.substr(0, /*len=*/sep_pos));
  // Value corresponds to the row from separator '=' to end
  const std::string value = ltrim(row.substr(sep_pos + 1));
  // Validation check
  if (key.empty() || value.empty())
    makeError(/*message=*/"expression 'key = value' expected");
  else
    settings.append(key, value);
}

void Config::makeError(const std::string& message)
{
  actualize<p__the(ConfigEffector::configParsingFailed)>
           (filename(), rowNumber, message);
  fail();
}

void Config::fail()
{
  actualize<p__the(ConfigEffector::configCannotParsed)>();
}

std::string Config::filename() const
{
  std::string name = filePath;
  //
  const size_t pos = name.rfind('/');
  if (pos != std::string::npos)
    name.erase(0, /*len=*/pos + 1); // keep only the filename
  //
  return name;
}

std::string Config::ignoreComment(const std::string& src_row) const
{
  std::string row = src_row;
  //
  if (!row.empty()) {
    const size_t pos = row.find('#');
    // Removes comment
    if (pos != std::string::npos)
      row.erase(pos);
  }
  //
  return row;
}

std::string Config::trim(const std::string& src_row) const
{
  // Trims all (right and left) whitespaces
  return ltrim(rtrim(src_row));
}

std::string Config::rtrim(const std::string& src_row) const
{
  std::string row = src_row;
  //
  if (!row.empty()) {
    const size_t pos = row.find_last_not_of(" \t");
    // Trims right whitespaces
    if (pos != std::string::npos)
      row.erase(pos + 1);
    else // row is all whitespace
      row.clear();
  }
  //
  return row;
}

std::string Config::ltrim(const std::string& src_row) const
{
  std::string row = src_row;
  //
  if (!row.empty()) {
    const size_t pos = row.find_first_not_of(" \t");
    // Trims left whitespaces
    if (pos != std::string::npos)
      row.erase(0, /*len=*/pos);
    else // row is all whitespace
      row.clear();
  }
  //
  return row;
}
