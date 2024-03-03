#pragma once

// Adaptee
struct Square {
  explicit Square(const int side) : side(side) {}
  int side = 0;
};

// Target interface
struct Rectangle {
  virtual int width() const = 0;
  virtual int height() const = 0;
  int area() const { return width() * height(); }
};

// Object Adapter pattern: Adapter implementes interface.
struct SquareToRectangleAdapter : Rectangle {
  SquareToRectangleAdapter(const Square& square) : square(square) {}

  int width() const override { return square.side; }

  int height() const override { return square.side; }

  const Square& square;
};