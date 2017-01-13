#include <iostream>
#include <cstring>
#include <cstdlib>
#include <sstream>
#include <vector>
#include <cmath>
#include <stack>

class Solution {
public:
  std::string countAndSay(int n) {
    std::stack<char> stk;
    std::string prev = "21";
    std::string next = "";
    int count = 0;
    if(n == 1)
      return "1";
    if(n == 2)
      return "11";
    if(n == 3)
      return "21";
    for(int i = 3 ; i < n ; ++i) {
      std::string::iterator it = prev.begin();
      char top;
      while(it != prev.end()) {
        if(!stk.empty()) {
          top = stk.top();
          if(top != *it) {
            // pop all from stack
            while(!stk.empty()) {
              top = stk.top();
              stk.pop();
              ++count;
            }
            std::stringstream ss;
            ss << count;
            next = next + ss.str() + top;
            stk.push(*it);
            count = 0;
          } else {
            stk.push(*it);
          }
        } else {
          stk.push(*it);
        }
        ++it;
      }
      // Flush
      if(!stk.empty()) {
        while(!stk.empty()) {
          top = stk.top();
          stk.pop();
          ++count;
        }
        std::stringstream ss;
        ss << count;
        next = next + ss.str() + top;
      }
      prev = next;
      count = 0;
      next = "";
    } 
    
    return prev;
  }
};

int main() {
  Solution s;
  std::cout << s.countAndSay(6) << std::endl; 
  return 0;
}
