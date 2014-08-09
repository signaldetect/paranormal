#ifndef _CONTRIB_CONFIG_H_
#define _CONTRIB_CONFIG_H_

#include <p/eventer.h>
#include <string>
#include <fstream> // std::ifstream, std::getline
#include <unordered_set>

#include "nodes.h" // + Node
#include "settings.h"

// Actualizer
#include "configeffector.h"

// Effectors
#include "../gameeffector.h"
#include "nodeeffector.h" // + std::string
#include "settingeffector.h" // + std::string

/**
 * Config
 * Class definition
 *
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
class Config : public p::Eventer<p::Act<ConfigEffector>,
                                 GameEffector,
                                 NodeEffector,
                                 SettingEffector> {
private:
  bool parsing = true;

  const std::string filePath = "../resrc/config.txt";
  std::ifstream file; // configuration file stream
  size_t rowNumber = 0; // current parsing row (line) number

  Nodes nodes; // expected and defined nodes
  std::unordered_set<std::string> wanted; // names of wanted (required) nodes

  Settings settings; // settings of current node

public:
  // Effects (Game)
  void gameLaunched() override;
  void gameStopped() override;

  // Effects (Node)
  void nodeExpected(const std::string& name, bool required) override;
  void nodeDoesNotExist(const std::string& name) override;

  // Effects (Setting)
  void settingDoesNotExist(const std::string& name) override;
  void settingDecodingFailed(const std::string& name,
                             const std::string& message) override;

private:
  void start();
  void parse();
  void parse(const std::string& row);
  void stop();

  void completeNode();
  void complete();

  void extractNodeName(const std::string& row);
  void extractSetting(const std::string& row, size_t sep_pos);

  void makeError(const std::string& message);
  void fail();

  std::string filename() const;

  std::string ignoreComment(const std::string& src_row) const;
  std::string trim(const std::string& src_row) const;
  std::string rtrim(const std::string& src_row) const;
  std::string ltrim(const std::string& src_row) const;
};

#endif /*_CONTRIB_CONFIG_H_*/
