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

// Similarly, it has very few attributes. It's really just the ones needed to identify an element.
struct attributes {
  std::string id;
  std::string className;
  std::string rawVal;
}
/*
Yeah, I know rawVal isn't a real attribute. This is a "special attribute", meaning it isn't for the website to set but rather for the renderer to set.
Basically, if an element contains raw text, it'll be placed inside a <rawvalmeta> tag, which is the only thing that can contain a rawVal attribute.
Trust me, this solves issues in the long run. I'm not gonna completely explain why I'm doing this tho.
*/

struct DOMElement {
  std::string tagname;
  styles styleAttributes;
  attributes normalAttributes;
  std::vector<DOMElement> childElements;
}

struct rawSection { // This can either be a tag, or raw text contents of a tag
  bool isTag;
  std::string contents;
}

std::vector<rawSection> parseRaw(std::string rawHTML) {
  bool arrowOpen = false;
  std::vector<rawSection> rawSections;
  rawSection rawSectBuffer;
  // WARNING: You are about to see a LOT of nested if-else statements. Sorry to anybody trying to debug this mess :P
  for (int ch = 0; ch < rawHTML.length(); ch++) {
    if (ch == '<') {
      arrowOpen = true;
      rawSectBuffer.isTag = true;
      rawSectBuffer.contents = "<";
      rawSections.push_back(rawSectBuffer);
    } else {
      if (arrowOpen) {
        rawSections[rawSections.length() - 1].contents += rawHTML[ch];
        if (rawHTML[ch] == '>')
          arrowOpen = false;
      } else {
        if (rawSections.length() - 2).contents[0] == '<') {
          rawSectBuffer.isTag = false;
          rawSectBuffer.contents = s(1, rawHTML[ch]);
          rawSections.push_back(rawSectBuffer);
        } else {
          rawSections[rawSections.length - 1].contents += rawHTML[ch];
        }
      }
    }
  }
  return rawSections;
}

std::vector<DOMElement> parseDOM(std::string rawHTML) {
  // Initialise a new DOM tree
  std::vector<DOMElement> toReturn;
  // Now it'll go full interpreter mode and try parse the whole contents. Firstly, it'll just read tags and contents (recurse for contents). Attributes and styles can be done later.
  std::vector<rawSection> rawParts = parseRaw(rawHTML);
  // Now for each element, [work out what i need to do next]
  return toReturn;
}
