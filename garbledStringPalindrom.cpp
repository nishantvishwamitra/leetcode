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

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
  bool isPalindrome(std::string s) {
    if(s.size() == 0) return true;
    std::string::iterator front = s.begin();
    std::string::reverse_iterator back = s.rbegin();
    while( front < back.base() ) {
      //std::cout << *front << " " << *back << std::endl;
      if(!isalnum(*front)) {++front; continue;}
      if(!isalnum(*back))  {++back; continue;}
      if(tolower(*front) != tolower(*back)) return false;
      ++front;
      ++back;
    }
    return true;
  }
};

int main() {
  Solution s;
  std::cout << s.isPalindrome("A man, nam       ...,, a") << std::endl;
  //std::cout << s.isPalindrome("A man, a plan, a canal: Panama") << std::endl;
  return 0;
}
