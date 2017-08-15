#include <iostream>
#include <cstdlib>
#include <sstream>
#include <vector>
#include <list>
#include <cmath>
#include <stack>
#include <string>
#include <map>
#include <algorithm>


class MinStack {
private:
  // To make it minstack, have two stacks.
  std::stack<int> main_stack; 
  std::stack<int> mins; 
public:
  /** initialize your data structure here. */
  MinStack() {
    
  }
 
  void push(int x) {
    main_stack.push(x);
    if(mins.empty()) {
      mins.push(x);
      return;
    }
    int min = mins.top();
    if(x <= min) {
      mins.push(x);
    }
  }
 
  void pop() {
    int _top = main_stack.top();
    main_stack.pop();
    if(_top == mins.top() ) {
      mins.pop();
    }
  }
 
  int top() {
    return main_stack.top();
  }
 
  int getMin() {
    return mins.top();
  }
};

int main() {
  MinStack *obj = new MinStack();
  obj->push(0);
  obj->push(1);
  obj->push(0);
  std::cout << obj->getMin() << std::endl; 
  obj->pop();
  std::cout << obj->getMin() << std::endl; 
  return 0;
}
