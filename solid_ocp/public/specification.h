#pragma once

template <typename T>
class Specification {
 public:
  virtual ~Specification() = default;
  virtual bool IsSatisfied(T* item) const = 0;

  // new: breaks OCP if you add it post-hoc
  /*AndSpecification<T> operator&&(Specification<T>&& other)
  {
    return AndSpecification<T>(*this, other);
  }*/
};