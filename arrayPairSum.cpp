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
  int arrayPairSum(std::vector<int>& nums) {
    std::sort(nums.begin(), nums.end());
    int sum = 0;
    for(int i = 0 ; i < nums.size() ; i += 2) {
      sum += (nums[i] < nums[i + 1] ? nums[i] : nums[i + 1]);
    }
    return sum;
  }
};

int main() {
  Solution s;
  std::vector<int> nums;
  nums.push_back(1);
  nums.push_back(4);
  nums.push_back(3);
  nums.push_back(2);
  std::cout << s.arrayPairSum(nums) << std::endl;
  return 0;
}
