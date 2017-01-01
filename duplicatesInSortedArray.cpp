#include <cstring>
#include <cstdlib>
#include <sstream>
#include <vector>
#include <cmath>

class Solution {
public:
  int removeDuplicates(std::vector<int>& nums) {
    if(nums.size() == 0) return 0;
    std::vector<int>::iterator it = nums.begin();
    while(it != nums.end() - 1) {
      if(*it == *(it + 1)) {
        it = nums.erase(it);
      } else
        ++it;
    }
    return nums.size();
  }
};

int main() {
  Solution s;
  std::vector<int> nums;
  nums.push_back(1);
  nums.push_back(1);
  nums.push_back(1);
  nums.push_back(3);
  nums.push_back(3);
  nums.push_back(5);
  std::cout << s.removeDuplicates(nums) << std::endl;
  return 0;
}
