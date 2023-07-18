#ifndef ARRAY_STACK_H
#define ARRAY_STACK_H
#include <string>

using namespace std;

//C++17 does not allow for dynamic specification exceptions.
/*
 * Exception class for an operation called on an empty stack.

/*
 * Array Based Stack Class Definition
 */
template <typename E>
  class ArrayStack {
    //default size, 1-1000
    enum { DEF_CAPACITY = 1000};
  public:
    ArrayStack(int cap = DEF_CAPACITY);
    //return number of items in stack
    int size() const;
    //return true if empty, else false.
    bool empty() const;
    //get the top element
    const E& top();
    //push an element on top of stack
    void push(const E& e);
    //pop an element off top of stack
    void pop();
  private:
    // array of stack elements
    E* S;
    //capacity of stack
    int capacity;
    //index of top of stack
    int t;
  };
#endif
