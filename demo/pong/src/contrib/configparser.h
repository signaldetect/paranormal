/**
 * Simple configuration file parser
 *
 * Configuration file format:
 * # Comment
 * node1_name:
 *   setting1_key = setting1_value
 *   setting2_key = setting2_value
 *   ...
 * node2_name: # comment
 *   setting_key = setting_value # comment
 * ...
 */

#ifndef _CONTRIB_CONFIGPARSER_H_
#define _CONTRIB_CONFIGPARSER_H_

#include <string>
#include <fstream> // std::ifstream, std::ios_base, std::getline
#include <sstream> // std::ostringstream

#include "settings.h"

/**
 * ConfigParser definition
 */

class ConfigParser {
public:
  struct Data {
    std::string node; // node name
    std::string key;
    std::string value;
  };

private:
  enum State {STARTING, SHIFTING, PARSING, STOPPING};
  State state;

  std::string path; // configuration file path
  std::ifstream file; // configuration file stream

  Data data; // fetched setting + its node name

  size_t rowNumber; // current parsing row (line) number
  std::string error; // last error message

public:
  ConfigParser(const std::string& file_path);
  ~ConfigParser();

  void initialize();

  const Data fetch();

  bool parsing() const;
  bool nodeCompleting() const;

  bool hasError() const;
  const std::string& errorMessage() const;

  std::string fileName() const;

private:
  void start();
  void stop();

  void parse();
  void parse(const std::string& row);

  void extractNodeName(const std::string& row);
  void extractSetting(const std::string& row, size_t sep_pos);

  std::string ignoreComment(const std::string& src_row) const;
  std::string trim(const std::string& src_row) const;
  std::string rtrim(const std::string& src_row) const;
  std::string ltrim(const std::string& src_row) const;

  template <class ...vt_Args>
  void makeErrorMessage(vt_Args&& ...args);

  template <class t_First, class ...vt_Rest>
  void makeMessage(std::ostringstream& stream,
                   t_First&& arg, vt_Rest&& ...args);

  void makeMessage(std::ostringstream& stream);
};

/**
 * ConfigParser implementation
 */

inline
ConfigParser::ConfigParser(const std::string& file_path)
  : path(file_path)
{
  initialize();
}

inline
ConfigParser::~ConfigParser()
{
  stop();
}

inline
void ConfigParser::initialize()
{
  state = STARTING;
  //
  data.node.clear();
  data.key.clear();
  data.value.clear();
  rowNumber = 0;
  error.clear();
}

const ConfigParser::Data ConfigParser::fetch()
{
  Data fetched_data;
  //
  // First start or restart the parser
  if (state == STARTING)
    start(); // state --> PARSING, SHIFTING or STOPPING
  //
  // Shifting to another node
  if (state == SHIFTING)
    parse(); // state --> PARSING, SHIFTING or STOPPING
  //
  // Parsing data for next fetch
  if (state == PARSING) {
    fetched_data = data; // data from previous parsing
    parse(); // state --> PARSING, SHIFTING or STOPPING
  }
  //
  // EOF or some error occurred
  if (state == STOPPING)
    stop();
  //
  return fetched_data;
}

inline
bool ConfigParser::parsing() const
{
  return (state != STOPPING);
}

inline
bool ConfigParser::nodeCompleting() const
{
  return (((state == SHIFTING) || (state == STOPPING)) && !hasError());
}

inline
bool ConfigParser::hasError() const
{
  return !error.empty();
}

inline
const std::string& ConfigParser::errorMessage() const
{
  return error;
}

std::string ConfigParser::fileName() const
{
  std::string name = path;
  //
  const size_t pos = name.rfind('/');
  if (pos != std::string::npos)
    name.erase(0, /*len=*/pos + 1); // keep only the filename
  //
  return name;
}

inline
void ConfigParser::start()
{
  // Opens configuration file
  if (file.is_open())
    file.seekg(0, std::ios_base::beg); // beginning of the file
  else
    file.open(path);
  // Checks the file after opening
  if (file.is_open())
    parse(); // parse data for fetch
  else {
    state = STOPPING;
    makeErrorMessage("error opening file");
  }
}

inline
void ConfigParser::stop()
{
  if (file.is_open())
    file.close();
}

inline
void ConfigParser::parse()
{
  state = PARSING;
  //
  std::string row;
  while (row.empty() && std::getline(file, row).good()) {
    ++rowNumber;
    row = trim(ignoreComment(row));
  }
  //
  if (file.good()) // => ready for row parsing
    parse(row);
  else // => EOF or some error on input operation
    state = STOPPING;
}

inline
void ConfigParser::parse(const std::string& row)
{
  size_t sep_pos = row.find("="); // position of the key-value separator
  if (sep_pos != std::string::npos) {
    // Setting available
    extractSetting(row, sep_pos);
  }
  else if (row.back() == ':') {
    // Current node is completing, shifting to another node
    state = SHIFTING;
    extractNodeName(row);
  }
  else {
    state = STOPPING;
    makeErrorMessage("row ", rowNumber, " is invalid");
  }
}

inline
void ConfigParser::extractNodeName(const std::string& row)
{
  // Node name corresponds to the row from start to ':'
  data.node = rtrim(row.substr(0, row.length() - 1));
  // Validation check
  if (data.node.empty()) {
    state = STOPPING;
    makeErrorMessage("node name expected before ':' token on row ", rowNumber);
  }
}

inline
void ConfigParser::extractSetting(const std::string& row, size_t sep_pos)
{
  // Key corresponds to the row from start to separator '='
  data.key = rtrim(row.substr(0, /*len=*/sep_pos));
  // Value corresponds to the row from separator '=' to end
  data.value = ltrim(row.substr(sep_pos + 1));
  // Validation check
  if (data.key.empty() || data.value.empty()) {
    state = STOPPING;
    makeErrorMessage("expression 'key = value' expected on row ", rowNumber);
  }
}

inline
std::string ConfigParser::ignoreComment(const std::string& src_row) const
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

inline
std::string ConfigParser::trim(const std::string& src_row) const
{
  // Trims all (right and left) whitespaces
  return ltrim(rtrim(src_row));
}

std::string ConfigParser::rtrim(const std::string& src_row) const
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

std::string ConfigParser::ltrim(const std::string& src_row) const
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

template <class ...vt_Args>
void ConfigParser::makeErrorMessage(vt_Args&& ...args)
{
  std::ostringstream stream;
  makeMessage(stream, args...);
  //
  const std::string message = stream.str();
  if (!message.empty())
    error = "Configuration file " + fileName() + ": " + message;
}

template <class t_First, class ...vt_Rest>
inline
void ConfigParser::makeMessage(std::ostringstream& stream,
                               t_First&& arg, vt_Rest&& ...args)
{
  stream << arg;
  makeMessage(stream, args...);
}

inline
void ConfigParser::makeMessage(std::ostringstream& /*stream*/)
{
}

#endif /*_CONTRIB_CONFIGPARSER_H_*/
