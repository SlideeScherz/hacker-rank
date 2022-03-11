#ifndef QUEUE_HPP_INCLUDED // include guard to prevent multiple declaration
#define QUEUE_HPP_INCLUDED

#include <stdexcept>
using namespace std;

/**
 * Base class for data structures implementing a queue (FIFO) interface.
 */


template <typename T>
class Queue
{
public:
  virtual bool empty() const = 0;
  virtual bool full() const = 0;
  virtual T const& front() const = 0;
  virtual T const& back() const = 0;
  virtual T dequeue() = 0;
  virtual void enqueue(T x) = 0;
};

/**
 * Generic implementation of a queue backed by a static array (fixed-capacity, contiguous, random-access).
 * Note: We use zero-based indexing here, as opposed to the 1-based indexing in the textbook.
 */
template <typename T>
class ArrayQueue : public Queue<T>
{
public:
    bool empty() const {
        return head == tail;
    }
    bool full() const {
        return cap == tail;
    }
    T const& front() const {
        if (empty()) throw std::out_of_range("Empty Queue");
        return q[head];
    }
    T const& back() const {
        if (tail == 0) return q[cap];
        else return q[tail - 1];
    }

    T dequeue() {

        if (empty())
            throw std::out_of_range("Queue Underflow");
        else {
            auto x = q[head];
            if (head == cap) head = 0;
            else head = head + 1;
            return x;
        }
    }
    void enqueue(T x) {
        if (full())
            throw std::length_error("Queue Overflow");
        else {
            q[tail] = x;
            if (tail == cap) tail = 0;
            else tail = tail + 1;
        }
    }

    void insertDequeBack(T x) {
        if (head == 0) {
            using namespace std;
            cout << "Queue Overflow";
            return;
        }

        if (head == -1) {
            head = 0;
            tail = 0;
            q[0] = x;
            return;
        }

        ++tail;
        q[tail] = x;
    }

    void insertDequeFront(T x) {
        if (head == 0)
            return;

        if (head == -1) {
            head = 0;
            tail = 0;
            q[0] = x;
            return;
        }

        --head;
        q[head] = x;
    }

    void deleteDequeBack() {
        if (tail == -1)
            return;
        if (head == tail) {
            front = -1;
            tail = -1;
            auto temp = q[tail];
        }

        auto temp2 = q[tail];
        --tail;
    }

    void deleteDequeFront() {
        if (head == tail) {
            head = -1;
            tail = -1;
            auto temp = q[head];
            return;
        }
        if (head == -1)
            return;

        auto temp2 = q[head];
        ++head;
    }
  
    ArrayQueue(int n = 10) : cap(n - 1), head(0), tail(head), q(new T[n]) {}

    ~ArrayQueue() { delete[] q; }

private:
    int cap;
    int head;
    int tail;
    T* q;
};

template <typename T>
class LinkedQueue : public Queue<T>
{
public:
    bool empty() const {
        return head == tail;
    }
    T dequeue() {        
        // If queue is empty, return out_of_range error. 
        if (empty()) {
            throw std::out_of_range("Queue Underflow");
            return;
        }

        // Move head node forward after storing it 
        auto x = q[temp];
        temp = head;
        head = head->next;

        // If head is empty, then make tail empty
        if (empty())
            tail = nullptr;

        delete (temp);
    }

    void enqueue(T x) {

        auto x = q[temp];
        // If queue is empty, make the temp node the head and tail 
        if (empty()) {
            head = tail = temp;
            return;
        }

        // Add the temp node at the tail and change pointer 
        tail->next = temp;
        tail = temp;
    }


    LinkedQueue(int n = 10) : head(0), tail(head), temp(1), q(new T[n]) {}

    ~LinkedQueue() { delete[] q; }

private:
    int head;
    int tail;
    int temp;
    T* q;
};

#endif // QUEUE_HPP_INCLUDED
