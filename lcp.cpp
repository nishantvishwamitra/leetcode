class Solution {
public:
  string longestCommonPrefix(vector<string>& strs) {
    if(strs.size() == 0) {
        return "";
    }
    std::string lcp = strs[0];
    std::string temp = "";
    for(int i = 1 ; i < strs.size() ; ++i) {
      std::string::iterator it = strs[i].begin();
      std::string::iterator lcpIt = lcp.begin();
      while(it != strs[i].end() || lcpIt != lcp.end()) {
        if(*it == *lcpIt) {
          temp = temp + *it;
        } else {
          lcp = temp;
          break;
        }
        ++it;
        ++lcpIt;
      }
      temp = "";
    }
    return lcp;
  }
};
