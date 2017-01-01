#include <iostream>
#include <cstring>
#include <cstdlib>
#include <sstream>
#include <vector>
#include <cmath>

class Solution {
public:
  std::string convert(std::string s, int numRows) {
    if(numRows == 1) return s;
    std::string res[numRows];
    for(int i = 0 ; i < numRows ; ++i) {
      res[i] = "";
    }
    std::string::iterator it = s.begin();
    int count = 0;
    bool flip = true;
    while(it != s.end()) {
      res[count] = res[count] + *it;
      if(flip)
        ++count;
      else
        --count;
      if(count == 0 || count == (numRows - 1))
        flip = !flip;
      ++it;
    }
    std::string done = "";
    for(int i = 0 ; i < numRows ; ++i) {
      done = done + res[i];
    }
    return done;
  }
};

int main() {
  Solution s;
  std::cout << s.convert("AB", 2) << std::endl;
  return 0;
}
