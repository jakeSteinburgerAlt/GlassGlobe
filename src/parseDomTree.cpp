// DOM tree parser for GlassGlobe web browser. This'll be used to parse HTML so it can later be rendered.
// Copyright (C) 2024 Jake Steinburger under the MIT license. See the github repository for more info.

#include <iostream>
#include <vector>

// Very few possible style properties for now.
struct styles {
  int colour[3];
  int bgcolour[3];
  float borderradius;
  float width;
  float height;
  float padding;
  float margin;
}

struct DOMElement {
  std::string tagname;
  styles styleAttributes;
  attributes normalAttributes;
}

// This assumes that everything is in one <html> tag, and nothing is outside.
// Ik a lot of websites don't use good practices and may not put everything in there, but it should be fine for most sites for now.
DOMElement parseDOM() {
  
}
