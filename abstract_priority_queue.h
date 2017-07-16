// DO NOT MODIFY THIS FILE
#ifndef _ABSTRACT_PRIORITY_QUEUE_H_
#define _ABSTRACT_PRIORITY_QUEUE_H_

// type T must be orderable (support relational operators, operator<, etc.)
template <typename T>
class AbstractPriorityQueue
{
public:

  // return true if the priority queue is empty
  virtual bool isEmpty() = 0;

  // insert item into the queue
  // may throw on allocation failure
  virtual void add(const T& item) = 0;

  // remove highest priority item from the queue
  // throws std::logic_error if queue is empty
  virtual void remove() = 0;

  // get the item with the highest priority from the queue
  // throws std::logic_error if queue is empty
  virtual T peek() = 0;
};

#endif // _ABSTRACT_PRIORITY_QUEUE_H_
