// ----------------------------------------------------------------------------
// IndexedContainer.h
//
//
// Authors:
// Peter Polidoro polidorop@janelia.hhmi.org
// ----------------------------------------------------------------------------
#ifndef INDEXED_CONTAINER_H
#define INDEXED_CONTAINER_H
#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif
#include "Array.h"


template <typename T, int MAX_SIZE>
class IndexedContainer
{
public:
  IndexedContainer();
  T& operator[](const int index);
  T& at(const int index);
  void clear();
  int add(const T &value);
  void remove(const int index);
  bool indexHasValue(const int index);
  int size();
  int max_size();
  bool empty();
  bool full();

private:
  Array<T,MAX_SIZE> values_;
  Array<bool,MAX_SIZE> available_;
  int size_;
};
#include "IndexedContainerDefinitions.h"

#endif
