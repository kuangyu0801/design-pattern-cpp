#pragma once

#include <sstream>
#include <string>
#include "shape.h"

class Circle : public Shape {
   
public:
    Circle() = default;
    Circle(float radius) : radius_(radius) {};
    void Resize(float factor) {
        radius_ *= factor;
    }
    std::string Str() const override {
        std::ostringstream oss;
        oss << "A circle of radius " << radius_;
        return oss.str();
    } 
private:
    float radius_;
};