// ----------------------------------------------------------------------------
// IndexedContainerDefinitions.h
//
//
// Authors:
// Peter Polidoro peterpolidoro@gmail.com
// ----------------------------------------------------------------------------
#ifndef INDEXED_CONTAINER_DEFINITIONS_H
#define INDEXED_CONTAINER_DEFINITIONS_H


template <typename T,
  size_t MAX_SIZE>
IndexedContainer<T,MAX_SIZE>::IndexedContainer()
{
  clear();
}

template <typename T,
  size_t MAX_SIZE>
const T & IndexedContainer<T,MAX_SIZE>::operator[](int index) const
{
  if ((index >= 0) && (index < (int)MAX_SIZE) && !available_[index])
  {
    return values_[index];
  }
  return values_[0]; // bad reference
}

template <typename T,
  size_t MAX_SIZE>
T & IndexedContainer<T,MAX_SIZE>::operator[](int index)
{
  if ((index >= 0) && (index < (int)MAX_SIZE) && !available_[index])
  {
    return values_[index];
  }
  return values_[0]; // bad reference
}

template <typename T,
  size_t MAX_SIZE>
const T & IndexedContainer<T,MAX_SIZE>::at(int index) const
{
  if ((index >= 0) && (index < (int)MAX_SIZE) && !available_[index])
  {
    return values_[index];
  }
  return values_[0]; // bad reference
}

template <typename T,
  size_t MAX_SIZE>
T & IndexedContainer<T,MAX_SIZE>::at(int index)
{
  if ((index >= 0) && (index < (int)MAX_SIZE) && !available_[index])
  {
    return values_[index];
  }
  return values_[0]; // bad reference
}

template <typename T,
  size_t MAX_SIZE>
void IndexedContainer<T,MAX_SIZE>::clear()
{
  size_ = 0;
  for (size_t index=0; index<MAX_SIZE; ++index)
  {
    available_[index] = true;
  }
}

template <typename T,
  size_t MAX_SIZE>
int IndexedContainer<T,MAX_SIZE>::add(const T &value)
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

template <typename T,
  size_t MAX_SIZE>
bool IndexedContainer<T,MAX_SIZE>::remove(int index)
{
  if ((index >= 0) && (index < (int)MAX_SIZE) && (!available_[index]))
  {
    available_[index] = true;
    --size_;
    return true;
  }
  return false;
}

template <typename T,
  size_t MAX_SIZE>
bool IndexedContainer<T,MAX_SIZE>::indexHasValue(int index)
{
  if ((index < 0) || (index >= (int)MAX_SIZE))
  {
    return false;
  }
  return !available_[index];
}

template <typename T,
  size_t MAX_SIZE>
size_t IndexedContainer<T,MAX_SIZE>::size()
{
  return size_;
}

template <typename T,
  size_t MAX_SIZE>
size_t IndexedContainer<T,MAX_SIZE>::max_size()
{
  return MAX_SIZE;
}

template <typename T,
  size_t MAX_SIZE>
bool IndexedContainer<T,MAX_SIZE>::empty()
{
  return size_ == 0;
}

template <typename T,
  size_t MAX_SIZE>
bool IndexedContainer<T,MAX_SIZE>::full()
{
  return size_ == MAX_SIZE;
}

template <typename T,
  size_t MAX_SIZE>
typename IndexedContainer<T,MAX_SIZE>::iterator IndexedContainer<T,MAX_SIZE>::begin()
{
  return iterator(this);
}

template <typename T,
  size_t MAX_SIZE>
typename IndexedContainer<T,MAX_SIZE>::iterator IndexedContainer<T,MAX_SIZE>::end()
{
  return iterator(this,MAX_SIZE);
}

template <typename T,
  size_t MAX_SIZE>
IndexedContainerIterator<T,MAX_SIZE> & IndexedContainerIterator<T,MAX_SIZE>::operator++()
{
  while (true)
  {
    ++position_;
    if ((position_ == MAX_SIZE) || (ic_ptr_->indexHasValue(position_)))
    {
      break;
    }
  }
  return *this;
}

template <typename T,
  size_t MAX_SIZE>
T & IndexedContainerIterator<T,MAX_SIZE>::operator*()
{
  while (true)
  {
    if (ic_ptr_->indexHasValue(position_))
    {
      return ic_ptr_->at(position_);
    }
    ++position_;
    if (position_ == MAX_SIZE)
    {
      return dummy_;
    }
  }
}
#endif
