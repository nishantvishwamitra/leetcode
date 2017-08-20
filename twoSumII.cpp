#include <iostream>
#include <cstdlib>
#include <sstream>
#include <vector>
#include <list>
#include <cmath>
#include <stack>
#include <string>
#include <map>
#include <algorithm>

/*class Solution {
public:
  std::vector<int> twoSum(std::vector<int>& numbers, int target) {
    std::map<int, int> table;
    std::vector<int> res;
    for(int i = 0 ; i < numbers.size() ; ++i) {
      std::map<int, int>::iterator it = table.find(target - numbers[i]);
      if(it != table.end()) {
        res.push_back(it->second + 1);
        res.push_back(i + 1);
        return res;
      } 
      table[numbers[i]] = i;
    }
    res.clear();
    return res;
  }
};*/

class Solution {
private:
  int binary_search(std::vector<int> numbers, int start, int end, int target) {
    if(start > end) return -1;
    //if(target == -145)
    //  std::cout << start << " " << end << std::endl;
    int mid = (start + end) / 2;
    if(numbers[mid] == target) {
      return mid;
    } else if(numbers[mid] < target) {
      return binary_search(numbers, mid + 1, end, target);
    } else {
      return binary_search(numbers, start, mid - 1, target);
    }
  }
public:
  std::vector<int> twoSum(std::vector<int>& numbers, int target) {
    for(int i = 0 ; i < numbers.size() ; ++i) {
      //std::cout << i << std::endl;
      int ind = binary_search(numbers, 0, numbers.size() - 1, target - numbers[i]);
      //std::cout << ind << std::endl;
      if(ind == i) continue;
      if(ind != -1) {
        std::vector<int> res;
        res.push_back(i + 1);
        res.push_back(ind + 1);
        std::sort(res.begin(), res.end());
        return res;
      }
    }
    std::vector<int> dummy;
    return dummy;  
  }
};

int main() {
  Solution s;
  std::vector<int> ip;
  ip.push_back(2);
  ip.push_back(3);
  ip.push_back(4);
  std::vector<int> res = s.twoSum(ip, 6);
  for(int i = 0 ; i < res.size() ; ++i)
    std::cout << res[i] << " ";
  std::cout << std::endl;
  return 0;
}
