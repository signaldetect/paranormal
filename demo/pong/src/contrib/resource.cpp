#include "resource.h"

void Resource::gameLaunched()
{
  // Loads the resource
  if (loading)
    load();
}

void Resource::gameStopped()
{
  // Game is terminated
  if (loading)
    loading = false;
}

void Resource::load()
{
  // Loads the text font
  if (font.loadFromFile("../resrc/sansation.ttf")) {
    actualize<p__the(ResourceEffector::resourceFontLoaded)>(font);
    // End of loading
    loading = false;
  }
  else {
    actualize<p__the(ResourceEffector::resourceFontNotFound)>
             (/*filename=*/"sansation.ttf");
    fail();
  }
}

void Resource::fail()
{
  actualize<p__the(ResourceEffector::resourceCannotLoaded)>();
}
