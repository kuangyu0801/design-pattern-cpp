#pragma once

#include <iostream>
#include <memory>
#include <string>

// Virtual proxy: deffer object construction when the actual method is called.

using std::cout;
using std::endl;
using std::string;

class Image {
 public:
  virtual void Draw() = 0;
};

class Bitmap : public Image {
 public:
  Bitmap(const string& filename) {
    cout << "Loading bitmap from " << filename << endl;
  }

  void Draw() override { cout << "Drawing bitmap" << endl; }
};

class LazyBitmap : public Image {
 public:
  LazyBitmap(const string& filename) : filename_(filename) {}
  void Draw() override {
    if (!bitmap_ptr) {
      // Delays construction of bitmap until method is called.
      bitmap_ptr = std::make_unique<Bitmap>(filename_);
    }
    bitmap_ptr->Draw();
  }

 private:
  string filename_;
  std::unique_ptr<Bitmap> bitmap_ptr;
};