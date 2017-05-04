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
  int climbStairs(int n) {
    if(n == 1) return 1;
    if(n == 2) return 2;
    int fir = 1, sec = 2, sum = 0, next = 0;
    for(int i = 2 ; i < n ; ++i){
      next = fir + sec;
      fir = sec;
      sec = next;
    }
    return next;
  }
};

int main() {
  Solution s;
  std::cout << s.climbStairs(10) << std::endl;
  return 0;
}
