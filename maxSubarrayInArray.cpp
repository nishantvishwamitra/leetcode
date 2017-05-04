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
  int maxSubArray(std::vector<int>& nums) {
    int here = 0, sofar = 0;
    for(int i = 0 ; i < nums.size() ; ++i) {
      here = here + nums[i];
      if(here < 0)
        here = 0;
      if(sofar < here)
        sofar = here;
    }
    if(sofar == 0 && std::find(nums.begin(), nums.end(), 0) == nums.end()) {
      return *std::max_element(nums.begin(), nums.end());
    }
    return sofar;
  }
};

int main() {
  Solution s;
  std::vector<int> nums;
  nums.push_back(-2);
  nums.push_back(1);
  nums.push_back(-3);
  nums.push_back(4);
  nums.push_back(-1);
  nums.push_back(2);
  nums.push_back(1);
  nums.push_back(-5);
  nums.push_back(4);
  std::cout << s.maxSubArray(nums) << std::endl;
  return 0;
}
