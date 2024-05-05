#pragma once
#include <cstdio>
#include <iostream>
#include <vector>

using std::endl;
using std::ostream;
using std::vector;

// Forward declaration.
struct Neuron;

// TODO(): This won't compile due to imcomplete type of forward declaration.
// CRTP: Curiously recurring template pattern
// template <typename T>
// struct NeuronContainer {
//   template <typename U>
//   void ConnectTo(U& other) {
//     for (Neuron& from : *static_cast<T*>(this)) {
//       for (Neuron& to : other) {
//         from.out.push_back(&other);
//         to.in.push_back(&from);
//       }
//     }
//   }
// };

struct Neuron /*: NeuronContainer<Neuron>*/ {
  vector<Neuron*> in;
  vector<Neuron*> out;
  unsigned int id;

  Neuron() {
    static int id = 1;
    this->id = id++;
  }

  void ConnectTo(Neuron& other) {
    out.push_back(&other);
    other.in.push_back(this);
  }

  /*template <typename T> void connect_to(T& other)
  {
    for (Neuron& target : other)
      connect_to(target);
  }*/

  // legal in MSVC only
  /*template<> void connect_to<Neuron>(Neuron& other)
  {
    out.push_back(&other);
    other.in.push_back(this);
  }*/

  // connect_to(vector<Neuron>&)

  Neuron* begin() { return this; }
  // In each iteration, this + 1 will be applied.
  Neuron* end() { return this + 1; }

  friend ostream& operator<<(ostream& os, const Neuron& obj) {
    for (Neuron* n_in : obj.in) {
      // in_id     -->     [cur_id]
      os << n_in->id << "\t-->\t[" << obj.id << "]" << endl;
    }

    for (Neuron* n_out : obj.out) {
      // [cur_id] ---> out_id
      os << "[" << obj.id << "]\t-->\t" << n_out->id << endl;
    }
    return os;
  }
};

struct NeuronLayer : vector<Neuron> /*,NeuronContainer<NeuronLayer>*/ {
  NeuronLayer(int count) {
    while (count-- > 0) {
      emplace_back(Neuron());
    }
  }

  friend ostream& operator<<(ostream& os, NeuronLayer& obj) {
    for (auto& n : obj) {
      os << n;
    }
    return os;
  }
};
