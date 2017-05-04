#include <iostream>
#include <cstring>
#include <cstdlib>
#include <sstream>
#include <vector>
#include <cmath>
#include <stack>
#include <string>
#include <map>
#include <algorithm>

class Solution {
public:
  int lengthOfLastWord(std::string s) {
    std::string::reverse_iterator itr = s.rbegin();
    int count = 0;
    while(itr != s.rend()) {
      if(*itr != ' ') {
        ++count;
      } else {
        if(count != 0)
          return count;
        else {
          if(s.size() != 1){
            ++itr;
            continue;
          }
          return 0;
        }
      }
      ++itr;
    }
    return count;
  }
};

int main() {
  Solution s;
  std::cout << s.lengthOfLastWord(" ") << std::endl;
  return 0;
}
  
