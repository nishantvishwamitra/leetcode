#include <iostream>
#include <cstring>
#include <cstdlib>
#include <sstream>
#include <vector>
#include <cmath>
#include <stack>

class Solution {
public:
  int strStr(std::string haystack, std::string needle) {
    if(needle == "") return 0;
    std::string::iterator itN = needle.begin();
    std::string::iterator itH = haystack.begin();
    int count = 0;
    int hayCount = 0;
    while(itH != haystack.end()) {
      if(*itH == *itN) {
        if(*(itH + needle.length() - 1) == *(itN + needle.length() - 1)) {
          std::string::iterator itTemp = itH;
          while(itN != needle.end() && itTemp != haystack.end()) {
            if(*itN == *itTemp)
              ++count;
            else {
              count = 0;
              itN = needle.begin();
              break;
            }
            ++itN;
            ++itTemp;
          }
          if(count == needle.length())
            return hayCount;
        }
      }
      ++itH;
      ++hayCount;
    }
    return -1;
  }
};

int main() {
  Solution s;
  std::cout << s.strStr("stackstackneedlestackneedle", "needle") << std::endl; 
  return 0;
}
