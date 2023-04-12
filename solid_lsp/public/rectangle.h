// Objects in a program should be replaceable with instances of their subtypes
// w/o altering the correctness of the program
#pragma once

class Rectangle {
 protected:
  int width_, height_;

 public:
  Rectangle(const int width, const int height)
      : width_{width}, height_{height} {}

  int GetWidth() const { return width_; }
  virtual void SetWidth(const int width) { this->width_ = width; }
  int GetHeight() const { return height_; }
  virtual void SetHeight(const int height) { this->height_ = height; }

  int Area() const { return width_ * height_; }
};

class Square : public Rectangle {
 public:
  Square(int size) : Rectangle(size, size) {}
  void SetWidth(const int width) override { this->width_ = height_ = width; }
  void SetHeight(const int height) override { this->height_ = width_ = height; }
};

struct RectangleFactory {
  static Rectangle CreateRectangle(int w, int h) {
    return Rectangle(w, h);
  };

  static Rectangle CreateSquare(int size) {
    return Rectangle(size, size);
  };
};
