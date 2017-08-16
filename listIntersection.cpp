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

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
  ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    ListNode *pa = headA;
    ListNode *pb = headB;
    while(true) {
      std::cout << (pa == NULL ? 800 : pa->val) << ' ' << (pb == NULL ? 800 : pb->val) << std::endl;
      if(pa == NULL && pb == NULL) return NULL;
      if(pa == pb) {
        return pa;
      }
      if(pa == NULL) {
        pa = headB;
        pb = pb->next;
        continue;
      }
      if(pb == NULL) {
        pb = headA;
        pa = pa->next;
        continue;
      }

      pa = pa->next;
      pb = pb->next;
    }
  }
};

int main() {
  ListNode *headA = new ListNode(3);
  /*headA->next = new ListNode(2); 
  headA->next->next = new ListNode(3); 
  headA->next->next->next = new ListNode(4);*/ 

  ListNode *headB = new ListNode(2);
  //headB->next = new ListNode(3);
  headB->next = headA;
  Solution s;
  ListNode *res = s.getIntersectionNode(headA, headB);
  std::cout << (res == NULL ? 800 : res->val) << std::endl; 
  return 0;
}
