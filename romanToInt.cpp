#include <iostream>
#include <cstring>
#include <cstdlib>
#include <sstream>
#include <vector>
#include <cmath>
#include <stack>
#include <string>
#include <map>

class Solution {
public:
  int romanToInt(std::string s) {
    static std::map<char, int> symbols;
    symbols['I'] = 1;
    symbols['V'] = 5;
    symbols['X'] = 10;
    symbols['L'] = 50;
    symbols['C'] = 100;
    symbols['D'] = 500;
    symbols['M'] = 1000;
    
    std::string::iterator itr = s.begin();
    int num = 0;
    while(itr != s.end()) {
      std::map<char, int>::const_iterator val = symbols.find(*itr);
      if(val == symbols.end())
        return -1;

      if( (itr + 1) != s.end() && val->second < symbols.find( *(itr + 1) )->second )
        num = num - val->second;
      else
        num = num + val->second;
      ++itr;
    }
    return num;
  }
};

int main() {
  Solution s;
  
  std::cout << s.romanToInt("MCMXCVI") << std::endl;
  return 0;
}
