#include "resource.h"

#include "configparser.h"
#include "confignode.h" // + Settings

void Resource::gameLaunched()
{
  loadFont();
  loadConfig();
}

void Resource::loadFont()
{
  // Loads the text font
  if (font.loadFromFile("../resrc/sansation.ttf"))
    actualize<p__the(ResourceEffector::resourceFontLoaded)>(font);
  else
    actualize<p__the(ResourceEffector::resourceErrorDetected)>
             (/*message=*/"File sansation.ttf not found");
}

void Resource::loadConfig()
{
  ConfigParser config(/*file_path=*/"../resrc/config.txt");
  ConfigParser::Data data;
  Settings settings;
  // Loads the configuration
  while (config.parsing()) {
    data = config.fetch();
    settings.append(data.key, data.value);
    //
    if (config.nodeCompleting()) {
      ConfigNode node(/*node_name=*/data.node);
      node.swap(settings); // => content in node, settings is empty
      actualize<p__the(ResourceEffector::resourceConfigLoading)>(node);
    }
  }
  //
  if (config.hasError()) {
    actualize<p__the(ResourceEffector::resourceErrorDetected)>
             (/*message=*/config.errorMessage());
  }
}
