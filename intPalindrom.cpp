#include <iostream>
#include <cstring>
#include <cstdlib>
#include <sstream>
#include <vector>
#include <cmath>
//This should be faster as it is O(N/2). My earlier soln was comparing original and reversed number, whis is O(N).
class Solution {
public:
  bool isPalindrome(int x) {
    std::ostringstream oss;
    oss << x;
    std::string orig = oss.str();
    std::string::iterator it = orig.begin();
    std::string::reverse_iterator rIt = orig.rbegin();
    int m = orig.length() / 2;
    int count = 0, rCount = orig.length() - 1; 
    bool switcher = (orig.length() % 2) == 0;
    while((count != rCount && !switcher) || (rCount > count && switcher)) {
      if(*it != *rIt)
        return false;
      ++count;
      --rCount;
      ++it;
      ++rIt;
    }
    return true;
  } 
};

int main() {
  Solution s;
  std::cout << s.isPalindrome(3011203) << std::endl;
  return 0;
}
