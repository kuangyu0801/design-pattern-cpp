#pragma once

#include <iostream>
#include <memory>
#include <ostream>
#include <sstream>
#include <string>
#include <vector>

// forward declaration
struct HtmlBuilder;

class HtmlElement {
  // All constructor are private.
  friend class HtmlBuilder;
  using string = std::string;

  string name;
  string text;
  std::vector<HtmlElement> elements;
  const size_t indent_size = 2;

  HtmlElement() {}
  HtmlElement(const string& name, const string& text)
      : name(name), text(text) {}
public:
  string Str(int indent = 0) const {
    std::ostringstream oss;
    string i(indent_size * indent, ' ');
    oss << i << "<" << name << ">" << std::endl;
    if (text.size() > 0) {
      oss << string(indent_size * (indent + 1), ' ') << text << std::endl;
    }

    // Appends the children elements.
    for (const auto& e : elements) {
      oss << e.Str(indent + 1);
    }
    oss << i << "</" << name << ">" << std::endl;
    return oss.str();
  }

  static std::unique_ptr<HtmlBuilder> Create(string root_name) {
    return std::make_unique<HtmlBuilder>(root_name);
  }
};

struct HtmlBuilder {
  using string = std::string;
  HtmlBuilder(string root_name) { root.name = root_name; }

  // void to start with
  HtmlBuilder& AddChild(string child_name, string child_text) {
    HtmlElement e{child_name, child_text};
    root.elements.emplace_back(e);
    return *this;
  }

  // pointer based
  HtmlBuilder* AddChildPointer(string child_name, string child_text) {
    HtmlElement e{child_name, child_text};
    root.elements.emplace_back(e);
    return this;
  }

  string Str() { return root.Str(); }

  HtmlElement Build() const {
    return root;
  }
  operator HtmlElement() const { return root; }
  HtmlElement root;
};