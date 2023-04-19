#include <iostream>
#include <string>

#include "gtest/gtest.h"
#include "public/builder.h"

using namespace std;
namespace {
TEST(Builder, ConstructObjectWithoutBuilder) {
  // <p>hello</p>
  auto text = "hello";
  string output;
  output += "<p>";
  output += text;
  output += "</p>";
  printf("<p>%s</p>", text);

  // <ul><li>hello</li><li>world</li></ul>
  string words[] = {"hello", "world"};
  ostringstream oss;
  oss << "<ul>";
  for (auto w : words)
    oss << "  <li>" << w << "</li>";
  oss << "</ul>";
  printf("%s", oss.str().c_str());
}

TEST(Builder, ConstructObjectWithBuilder) {
  // Builder makes it easier to construct.
  HtmlBuilder builder{ "ul" };
  // Flutter style.
  builder.AddChild("li", "hello").AddChild("li", "world");
  cout << builder.Str() << endl;
}

TEST(Builder, StaticCreatetObjectWithHtmlElement) {
  std::unique_ptr<HtmlBuilder> builder = HtmlElement::Create("ul");
  builder->AddChildPointer("li", "hello")->AddChildPointer("li", "world");
  cout << builder->Str() << endl;
}

TEST(Builder, StaticCreatetObjectWithHtmlElementBuild) {
  HtmlElement root = HtmlElement::Create("ul")->AddChildPointer("li", "hello")->Build();
  cout << root.Str() << endl;
}
}  // namespace