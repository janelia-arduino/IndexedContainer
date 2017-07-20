// ----------------------------------------------------------------------------
// IndexedContainerDefinitions.h
//
//
// Authors:
// Peter Polidoro polidorop@janelia.hhmi.org
// ----------------------------------------------------------------------------
#ifndef INDEXED_CONTAINER_DEFINITIONS_H
#define INDEXED_CONTAINER_DEFINITIONS_H


template <typename T, size_t MAX_SIZE>
IndexedContainer<T,MAX_SIZE>::IndexedContainer()
{
  clear();
}

template <typename T, size_t MAX_SIZE>
T& IndexedContainer<T, MAX_SIZE>::operator[](const int index)
{
  if ((index >= 0) && (index < (int)MAX_SIZE) && !available_[index])
  {
    return values_[index];
  }
}

template <typename T, size_t MAX_SIZE>
T& IndexedContainer<T, MAX_SIZE>::at(const int index)
{
  if ((index >= 0) && (index < MAX_SIZE) && !available_[index])
  {
    return values_.at(index);
  }
}

template <typename T, size_t MAX_SIZE>
void IndexedContainer<T, MAX_SIZE>::clear()
{
  size_ = 0;
  for (size_t index=0; index<MAX_SIZE; ++index)
  {
    available_[index] = true;
  }
}

template <typename T, size_t MAX_SIZE>
int IndexedContainer<T, MAX_SIZE>::add(const T &value)
{
  if (size_ < MAX_SIZE)
  {
    bool found_available = false;
    int index = -1;
    while (!found_available && (++index < (int)MAX_SIZE))
    {
      found_available = available_[index];
    }
    if (found_available)
    {
      values_[index] = value;
      available_[index] = false;
      ++size_;
      return index;
    }
  }
  return -1;
}

template <typename T, size_t MAX_SIZE>
bool IndexedContainer<T, MAX_SIZE>::remove(const int index)
{
  if ((index >= 0) && (index < (int)MAX_SIZE) && (!available_[index]))
  {
    available_[index] = true;
    --size_;
    return true;
  }
  return false;
}

template <typename T, size_t MAX_SIZE>
bool IndexedContainer<T, MAX_SIZE>::indexHasValue(const int index)
{
  if ((index < 0) || (index >= (int)MAX_SIZE))
  {
    return false;
  }
  return !available_[index];
}

template <typename T, size_t MAX_SIZE>
size_t IndexedContainer<T, MAX_SIZE>::size()
{
  return size_;
}

template <typename T, size_t MAX_SIZE>
size_t IndexedContainer<T, MAX_SIZE>::max_size()
{
  return MAX_SIZE;
}

template <typename T, size_t MAX_SIZE>
bool IndexedContainer<T, MAX_SIZE>::empty()
{
  return size_ == 0;
}

template <typename T, size_t MAX_SIZE>
bool IndexedContainer<T, MAX_SIZE>::full()
{
  return size_ == MAX_SIZE;
}

#endif
