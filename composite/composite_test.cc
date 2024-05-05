#include "gtest/gtest.h"
#include "public/composite_exercise.h"
#include "public/creature.h"
#include "public/graph.h"
#include "public/neuron.h"

using std::cout;
using std::endl;

TEST(Composite, GroupObject) {
  Group root("root");
  Circle c1, c2;
  root.objects.push_back(&c1);

  Group subgroup("sub");
  subgroup.objects.push_back(&c2);

  root.objects.push_back(&subgroup);

  root.Draw();
}

TEST(Composite, Neurons) {
  Neuron n1;
  Neuron n2;
  n1.ConnectTo(n2);
  // [1]     -->     2
  // 1       -->     [2]
  std::cout << n1 << n2 << endl;
}

// TEST(Composite, NeuronsAndLayer) {
//   NeuronLayer l1(5);
//   Neuron n3;
//   l1.ConnectTo(n3);
// }

TEST(Composite, ArrayBackedproperty) {
  Creature creature;
  creature.set_strength(10);
  creature.set_agility(20);
  creature.set_intelligence(30);
  EXPECT_EQ(creature.Sum(), 60);
}

TEST(Composite, ContainsInteger) {
  SingleValue single_value{11};
  ManyValues other_values;
  other_values.add(22);
  other_values.add(33);
  ASSERT_EQ(66, Sum({&single_value, &other_values}));
}