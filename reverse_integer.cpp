class Solution {
public:
int reverse(int x) {
  bool isNeg = false;
  int temp;
  std::vector<int> vec;
  int size;
    
  if(x < 0) {
    isNeg = true;
    x = x * -1;
  }
  while(x != 0) {
    temp = x % 10;
    vec.push_back(temp);
    x = x / 10;
  }
  
  size = vec.size();
  temp = 0; 
  int mult = size - 1;
  int a = 0, b = 0;
  for(int i = 0 ; i < size ; ++i) {
    a = temp;
    b = vec[i] * pow(10, mult);
    temp = a + b;
    if(temp < a || temp < b)
      return 0;
    --mult;
  }
  if(isNeg) 
    return -1 * temp;
  else    
    return temp;
}
};
