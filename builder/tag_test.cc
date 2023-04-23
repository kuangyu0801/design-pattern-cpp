#include "public/tag.h"

#include "gtest/gtest.h"

TEST(Builder, GroovyStyle) {
  std::cout << 
    P {
        IMG{"http://pokemon.com/pikachu.png"}
        } 
    << std::endl;
}