#include "gtest/gtest.h"

#include "public/list_strategy.h"
#include "public/text_processor.h"
#include "public/output_format.h"
#include <iostream>

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