#include <iostream>
#include <cstring>
#include <cstdlib>
#include <sstream>
#include <vector>
#include <cmath>
#include <stack>


class Solution {
public:
  int searchInsert(std::vector<int>& nums, int target) {
    
    for(int i = 0 ; i < nums.size() ; ++i) {
      if( (nums[i] == target) || (nums[i] > target) ) {
        return i;
      }
    } 
    return nums.size(); 
  }
};

int main() {
  Solution s;
  std::vector<int> nums;
  nums.push_back(1);
  nums.push_back(3);
  nums.push_back(5);
  nums.push_back(6);
  std::cout << s.searchInsert(nums, 7) << std::endl;
  return 0;
}
 
