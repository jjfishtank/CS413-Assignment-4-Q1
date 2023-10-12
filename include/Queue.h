// Queue.h
// Author: Jeremy Renati
// Created: 10/11/2023
// Simple int Array Queue with fixed size. Includes toSting function.

#pragma once

#include <string>
#include <stdexcept>

class Queue {
public:
  Queue(int maxSize);
  ~Queue() { delete[] items; }

  void enqueue(int newItem);
  int dequeue();

  std::string toString();
  void makeEmpty();

  bool isEmpty() { return numItems == 0; }
  bool isFull() { return numItems == maxItems; }

  int size() const { return numItems; }

private:
  int front;
  int back;
  int* items;
  int maxItems;
  int numItems;
};

inline Queue::Queue(int maxSize) : front(0), back(maxSize - 1), maxItems(maxSize), numItems(0) {
  items = new int[maxSize];
}

inline void Queue::enqueue(int newItem) {
  if (isFull()) {
    throw std::runtime_error("Queue full");
  }

  back = (back + 1) % maxItems;
  items[back] = newItem;
  numItems++;
}

inline int Queue::dequeue() {
  if (isEmpty()) {
    throw std::runtime_error("Queue empty");
  }

  int frontItem = items[front];
  front = (front + 1) % maxItems;
  numItems--;
  return frontItem;
}

inline std::string Queue::toString() {
  std::string result;
  int current = front;
  for (int i = 0; i < numItems; ++i) {
    result += std::to_string(items[current]) + " ";
    current = (current + 1) % maxItems;
  }
  return result;
}

inline void Queue::makeEmpty() {
  front = 0;
  back = maxItems - 1;
  numItems = 0;
}
