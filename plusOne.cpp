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
  std::vector<int> plusOne(std::vector<int>& digits) {
    int num, carry = 0;
    for(int i = digits.size() - 1 ; i >= 0 ; --i) {
      if(i == digits.size() - 1) {
        num = digits[i] + 1;
        if(num == 10) {
          digits[i] = 0;
          carry = 1;
        } else {
          digits[i] = num;
          carry = 0; 
        }
      } else {
        num = digits[i] + carry;
        if(num == 10) {
          digits[i] = 0;
          carry = 1;
        } else {
          digits[i] = num;
          carry = 0; 
        }
      }
    }
    if(carry != 0) {
      std::vector<int>::iterator it = digits.begin();
      digits.insert(it, carry);
    }
    return digits;
  }
};

int main() {
  std::vector<int> digits;
  digits.push_back(9);
  digits.push_back(9);
  digits.push_back(9);
  digits.push_back(9);
  Solution s;
  digits = s.plusOne(digits);
  for(int i = 0 ; i < digits.size() ; ++i)
    std::cout << digits[i] << " ";
  std::cout << std::endl;
  return 0;
}
