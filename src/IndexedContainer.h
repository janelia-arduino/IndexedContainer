// ----------------------------------------------------------------------------
// IndexedContainer.h
//
//
// Authors:
// Peter Polidoro peterpolidoro@gmail.com
// ----------------------------------------------------------------------------
#ifndef INDEXED_CONTAINER_H
#define INDEXED_CONTAINER_H
#include <Arduino.h>


template <typename T, size_t MAX_SIZE>
class IndexedContainer
{
public:
  IndexedContainer();
  T& operator[](const int index);
  T& at(const int index);
  void clear();
  int add(const T &value);
  bool remove(const int index);
  bool indexHasValue(const int index);
  size_t size();
  size_t max_size();
  bool empty();
  bool full();

private:
  T values_[MAX_SIZE];
  bool available_[MAX_SIZE];
  size_t size_;
};
#include "IndexedContainer/IndexedContainerDefinitions.h"

#endif
