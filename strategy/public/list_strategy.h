#pragma once

#include <sstream>

class ListStrategy {
 public:
  using ostringstream = std::ostringstream;
  using string = std::string;
  virtual ~ListStrategy() = default;
  virtual void Start(ostringstream& oss) {}
  virtual void AddListItem(ostringstream& oss, const string& item) = 0;
  virtual void End(ostringstream& oss) {}
};

class MarkdownListStrategy : public ListStrategy {
 public:
  void AddListItem(std::ostringstream& oss, const std::string& item) override {
    oss << " * " << item << std::endl;
  }
};

class HtmlListStrategy : public ListStrategy {
 public:
  void Start(ostringstream& oss) override { oss << "<ul>" << std::endl; }

  void End(ostringstream& oss) override { oss << "</ul>" << std::endl; }

  void AddListItem(ostringstream& oss, const string& item) override {
    oss << "<li>" << item << "</li>" << std::endl;
  }
};