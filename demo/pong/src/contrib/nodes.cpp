#include "nodes.h"

/**
 * Nodes
 * Class implementation
 */

void Nodes::append(const std::string& name, bool defined)
{
  if (count(name) == 0)
    emplace(name, defined);
  else if (defined)
    at(name) = true; // => node is defined now
}

void Nodes::activate(const std::string& name)
{
  append(name, /*defined=*/true);
  cursor = find(name);
}

void Nodes::purge()
{
  // Clears all
  cursor = cend();
  clear();
}

bool Nodes::hasActive() const
{
  return (cursor != cend());
}

bool Nodes::active(const std::string& name, bool required) const
{
  if (count(name) > 0) {
    if ((*cursor).first == name)
      return true;
    // Checks whether the node named 'name' shouldn't be required
    if (!required || at(name)) // => it shouldn't or it's defined (activated)
      return false;
  }
  // Otherwise
  Node{name, required}; // expected node
  return false;
}
