#include <iostream>
//#include <cstring>
#include <cstdlib>
#include <sstream>
#include <vector>
#include <list>
#include <cmath>
#include <stack>
#include <string>
#include <map>
#include <algorithm>

class Solution {
public:
  std::vector< std::vector<int> > generate(int numRows) {
    std::vector< std::vector<int> > outer;
    outer.reserve(numRows);
    for(int i = 0 ; i < numRows ; ++i) {
      std::vector<int> inner;
      inner.reserve(i + 1);
      if(i != 0) {
        std::vector<int> prev = outer[i - 1];
        inner.push_back(prev[0]);
        for(int j = 0 ; j < (prev.size() - 1) ; ++j) {
          inner.push_back(prev[j] + prev[j + 1]);
        }
        inner.push_back(prev[prev.size() - 1]);
        outer.push_back(inner);
      } else {
        inner.push_back(1);
        outer.push_back(inner);
      }
    }
    return outer;
  }
};

int main() {
  Solution s;
  std::vector< std::vector<int> > res = s.generate(7);
  for(int i = 0 ; i < 7 ; ++i) {
    for(int j = 0 ; j < i + 1 ; ++j) {
      std::cout << res[i][j] << " ";
    }
    std::cout << std::endl;
  }
  return 0;
}
