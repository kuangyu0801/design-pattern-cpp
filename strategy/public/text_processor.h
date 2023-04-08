#pragma once

#include <memory>
#include <sstream>
#include <string>
#include <vector>

#include "list_strategy.h"
#include "output_format.h"

class TextProcessor {
  using string = std::string;

 public:
  void Clear() {
    oss_.str("");
    oss_.clear();
  }

  void AppendList(const std::vector<string>& items) {
    strategy_->Start(oss_);
    for (auto& item : items) {
      strategy_->AddListItem(oss_, item);
    }
    strategy_->End(oss_);
  }

  void SetOutputFormat(const OutputFormat& format) {
    // Dynamic strategy selection.
    switch (format) {
      case OutputFormat::kMarkdown:
        strategy_ = std::make_unique<MarkdownListStrategy>();
        break;
      case OutputFormat::kHtml:
        strategy_ = std::make_unique<HtmlListStrategy>();
        break;
      default:
        throw std::runtime_error("Unsupported strategy.");
    }
  }
  string Str() const { return oss_.str(); }

 private:
 private:
  std::ostringstream oss_;
  std::unique_ptr<ListStrategy> strategy_;
};