#include <iostream>

#include "gtest/gtest.h"
#include "public/list_strategy.h"
#include "public/output_format.h"
#include "public/text_processor.h"

using namespace std;

TEST(Strategy, DynamicStratygy) {
  // markdown
  TextProcessor tp;
  tp.SetOutputFormat(OutputFormat::kMarkdown);
  tp.AppendList({"foo", "bar", "baz"});
  cout << tp.Str() << endl;

  // html
  tp.Clear();
  tp.SetOutputFormat(OutputFormat::kHtml);
  tp.AppendList({"foo", "bar", "baz"});
  cout << tp.Str() << endl;
}

TEST(Strategy, StaticStratygy) {
  StaticTextProcessor<MarkdownListStrategy> tp;
  tp.AppendList({"foo", "bar", "baz"});
  cout << tp.Str() << endl;

  StaticTextProcessor<HtmlListStrategy> tp_html;
  tp_html.AppendList({"foo", "bar", "baz"});
  cout << tp_html.Str() << endl;
}