#include <iostream>

#include "gtest/gtest.h"
#include "public/list_strategy.h"
#include "public/text_processor.h"

using namespace std;

TEST(Strategy, DynamicStratygy) {
  // markdown
  TextProcessor tp;
  tp.SetOutputFormat(OutputFormat::kMarkdown);
  tp.AppendList({"foo", "bar", "baz"});
  // Expected output:
  //  * foo
  //  * bar
  //  * baz
  cout << tp.Str() << endl;

  tp.Clear();
  // Switch to HTML.
  tp.SetOutputFormat(OutputFormat::kHtml);
  tp.AppendList({"foo", "bar", "baz"});
  cout << tp.Str() << endl;
  // Expected output:
  // <ul>
  // <li>foo</li>
  // <li>bar</li>
  // <li>baz</li>
  // </ul>
}

TEST(Strategy, StaticStratygy) {
  StaticTextProcessor<MarkdownListStrategy> tp;
  tp.AppendList({"foo", "bar", "baz"});
  cout << tp.Str() << endl;

  StaticTextProcessor<HtmlListStrategy> tp_html;
  tp_html.AppendList({"foo", "bar", "baz"});
  cout << tp_html.Str() << endl;
}