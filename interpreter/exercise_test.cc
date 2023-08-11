#include "public/exercise.h"

#include "gtest/gtest.h"

TEST(Interpreter, ExerciseExample1) {
  ExpressionProcessor expre_processor;
  EXPECT_EQ(1, expre_processor.Calculate("1"));
};

TEST(Interpreter, ExerciseExample2) {
  ExpressionProcessor expre_processor;
  EXPECT_EQ(3, expre_processor.Calculate("1+2"));
};

TEST(Interpreter, ExerciseExample3) {
  ExpressionProcessor expre_processor;
  EXPECT_EQ(6, expre_processor.Calculate("1+2+3"));
};