// ----------------------------------------------------------------------------
// IndexedContainerIterator.h
//
//
// Authors:
// Peter Polidoro peter@polidoro.io
// ----------------------------------------------------------------------------
#ifndef INDEXED_CONTAINER_ITERATOR_H
#define INDEXED_CONTAINER_ITERATOR_H

template <typename T,
  size_t MAX_SIZE>
class IndexedContainer;

template <typename T,
  size_t MAX_SIZE>
class IndexedContainerIterator
{
public:
  IndexedContainerIterator(IndexedContainer<T,MAX_SIZE> * ic_ptr) : ic_ptr_{ic_ptr}, position_{0} {}

  IndexedContainerIterator(IndexedContainer<T,MAX_SIZE> * ic_ptr, size_t size) : ic_ptr_{ic_ptr}, position_{size} {}

  bool operator!=(IndexedContainerIterator<T,MAX_SIZE> & other) const
  {
    return !(*this == other);
  }

  bool operator==(IndexedContainerIterator<T,MAX_SIZE> & other) const
  {
    return ((ic_ptr_->size() == 0) || (position_ == other.position_));
  }

  IndexedContainerIterator<T,MAX_SIZE> & operator++();

  T & operator*();

private:
  IndexedContainer<T,MAX_SIZE> * ic_ptr_;
  size_t position_;
  T dummy_;
};

#endif
