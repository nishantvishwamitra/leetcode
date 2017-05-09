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
  std::string addBinary(std::string a, std::string b) {
    if(a == "0" && b == "0")
      return "0";
    char carry = '0';
    std::string res = "";
    std::string::reverse_iterator ita = a.rbegin();
    std::string::reverse_iterator itb = b.rbegin();
    while(ita != a.rend() || itb != b.rend()) {
      if(ita != a.rend() && itb != b.rend()) {
        if(carry == '0') {
          if(*ita == '0' && *itb == '0') {
            res.append("0");
          } else if(*ita == '0' && *itb == '1') {
            res.append("1");
          } else if(*ita == '1' && *itb == '0') {
            res.append("1");
          } else { // 1, 1
            res.append("0");
            carry = '1';
          }
        } else {
          if(*ita == '0' && *itb == '0') {
            res.append("1");
            carry = '0';
          } else if(*ita == '0' && *itb == '1') {
            res.append("0");
            carry = '1';
          } else if(*ita == '1' && *itb == '0') {
            res.append("0");
            carry = '1';
          } else { // 1, 1
            res.append("1");
            carry = '1';
          }
        }
        ++ita;
        ++itb;
      } else if(ita == a.rend() && itb != b.rend()) {
        if(carry == '0') {
          if(*itb == '0') {
            res.append("0");
          } else if(*itb == '1') {
            res.append("1");
          } 
        } else {
          if(*itb == '0') {
            res.append("1");
            carry = '0';
          } else if(*itb == '1') {
            res.append("0");
            carry = '1';
          } 
        }
        ++itb;
      } else if(itb == b.rend() && ita != a.rend()) {
        if(carry == '0') {
          if(*ita == '0') {
            res.append("0");
          } else if(*ita == '1') {
            res.append("1");
          } 
        } else {
          if(*ita == '0') {
            res.append("1");
            carry = '0';
          } else if(*ita == '1') {
            res.append("0");
            carry = '1';
          } 
        }
        ++ita;
      }
    }
    //std::cout << "ita: " << *ita << " " << "itb: " << *itb << std::endl;
    //std::cout << "Res: " << res << " " << carry << std::endl;
    if(carry == '1')
      res.append("1");
    //else
      //res.append("0");
    std::reverse(res.begin(), res.end());
    // Remove leading 0s
    std::string::iterator it = res.begin();
    while(it != res.end()) {
      if(*it == '0')
        it = res.erase(it);
      else
        break;
      ++it;
    }
    return res;
  }
};

int main() {
  Solution s;
  std::cout << s.addBinary("11", "11") << std::endl;
  return 0;
}
