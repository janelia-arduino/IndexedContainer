// ----------------------------------------------------------------------------
// IndexedContainer.h
//
//
// Authors:
// Peter Polidoro peter@polidoro.io
// ----------------------------------------------------------------------------
#ifndef INDEXED_CONTAINER_H
#define INDEXED_CONTAINER_H
#include <Arduino.h>
#include "IndexedContainer/IndexedContainerIterator.h"


template <typename T,
  size_t MAX_SIZE>
class IndexedContainer
{
public:
  IndexedContainer();
  const T & operator[](int index) const;
  T & operator[](int index);
  const T & at(int index) const;
  T & at(int index);
  void clear();
  int add(const T &value);
  bool remove(int index);
  bool indexHasValue(int index);
  size_t size();
  size_t max_size();
  bool empty();
  bool full();
  typedef IndexedContainerIterator<T,MAX_SIZE> iterator;
  iterator begin();
  iterator end();

private:
  T values_[MAX_SIZE];
  bool available_[MAX_SIZE];
  size_t size_;
};
#include "IndexedContainer/IndexedContainerDefinitions.h"

#endif
