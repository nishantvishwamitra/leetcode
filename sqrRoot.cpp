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
  int mySqrt(int x) {
    if(x == 1) return 1;
    if(x == 0) return 0;
    int low = 0, high = x, mid = 0;
    while(low < high) {
      mid = (low + high) / 2;
      if(mid > x / mid)
        high = mid;
      else
        low = mid + 1;
    }
    return high - 1;
  }
};

int main() {
  Solution s;
  std::cout << s.mySqrt(30) << std::endl;
  return 0;
}
