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

#include <string> // + std::to_string
#include <fstream> // std::ifstream, std::ios_base, std::getline

/**
 * ConfigParser
 * Class definition
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
/*
  template <class ...vt_Args>
  void makeErrorMessage(vt_Args&& ...args);

  template <class t_First, class ...vt_Rest>
  void makeMessage(std::ostringstream& stream,
                   t_First&& arg, vt_Rest&& ...args);

  void makeMessage(std::ostringstream& stream);
*/
};

#endif /*_CONTRIB_CONFIGPARSER_H_*/
