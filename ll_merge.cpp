#include <iostream>
#include <cstring>
#include <cstdlib>
#include <sstream>
#include <vector>
#include <cmath>

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
      if(l1 == NULL && l2 == NULL)
        return NULL;
      if(l1 == NULL)
        return l2;
      if(l2 == NULL)
        return l1;
      ListNode* res = new ListNode(0);
      ListNode* head = res;
      while(l1 != NULL || l2 != NULL) {
        if((l2 == NULL && l1 != NULL) || ( l1 != NULL && l1->val < l2->val )) {
            res->next = l1;
            l1 = l1->next;
        } else if((l1 == NULL && l2 != NULL) || ( l2 != NULL && l1->val > l2->val )) {
            res->next = l2;
            l2 = l2->next;
        } else if(l1 != NULL && l2 != NULL && l1->val == l2->val) {
            res->next = new ListNode(l1->val);
            res = res->next;
            res->next = new ListNode(l2->val);
            l1 = l1->next;
            l2 = l2->next;
        }
        res = res->next;
      }
      return head->next;
    }
};

int main() {
  int a1[] = {2,4,5,8};
  int a2[] = {3,5,7,10};
  ListNode* l1 = new ListNode(2);
  ListNode* l2 = new ListNode(3);
  ListNode* h1 = l1;
  ListNode* h2 = l2;
  for(int i = 1 ; i < 4 ; ++i) {
    l1->next = new ListNode(a1[i]);
    l2->next = new ListNode(a2[i]);
    l1 = l1->next;
    l2 = l2->next;
  }
  
  /*while(h1 != NULL) {
    std::cout << "First: " << h1->val << " Second: " << h2->val << std::endl;
    h1 = h1->next;
    h2 = h2->next;
  }*/
  
  Solution s;
  ListNode* res = s.mergeTwoLists(h1, h2);
  while(res != NULL) {
    std::cout << res->val << std::endl;
    res = res->next;
  }
  return 0;
}
