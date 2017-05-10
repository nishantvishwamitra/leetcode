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
  void merge(std::vector<int>& nums1, int m, std::vector<int>& nums2, int n) {
    nums1.erase(nums1.begin() + m, nums1.end());
    nums2.erase(nums2.begin() + n, nums2.end());
    std::vector<int>::iterator it1 = nums1.begin();
    std::vector<int>::iterator it2 = nums2.begin();
    if(nums1.size() == 0) {
      nums1.insert(nums1.end(), nums2.begin(), nums2.end());
      return;
    }
    if(nums2.size() == 0) {
      return;
    }
    while(it1 != nums1.end()) {
      if(it2 == nums2.end()) break;
      if(*it1 == *it2) {
        it1 = nums1.insert(it1, *it2);
        ++it1;
        ++it2;
      } else if(*it1 > *it2) {
        it1 = nums1.insert(it1, *it2);
        ++it1;
        ++it2;
      } else if(*it1 < *it2) {
        ++it1;
      }
    }
    // Fill up
    while(it2 != nums2.end()) {
      nums1.push_back(*it2);
      ++it2;
    }
  }
};

int main() {
  Solution s;
  std::vector<int> nums1;
  std::vector<int> nums2;
  nums1.push_back(2);
  nums1.push_back(0);

  nums2.push_back(1);
  /*nums2.push_back(3);
  nums2.push_back(4);
  nums2.push_back(5);
  nums2.push_back(9);
  nums2.push_back(0);
  nums2.push_back(0);
  nums2.push_back(0);
  nums2.push_back(0);*/
  s.merge(nums1, 1, nums2, 1);
  for(int i = 0 ; i < nums1.size() ; ++i) 
    std::cout << nums1[i] << std::endl;
  return 0;
}
