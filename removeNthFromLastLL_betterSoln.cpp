#include <iostream>
#include <cstring>
#include <cstdlib>
#include <sstream>
#include <vector>
#include <cmath>
#include <stack>


struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
  public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
      ListNode* dummy = new ListNode(0);
      dummy->next = head;
      ListNode* first = dummy;
      ListNode* second = dummy;
      ListNode* prev = NULL;
      // Bring first, n ahead of second
      for(int i = 0 ; i < n ; ++i) {
        first = first->next;
      }
      while(first != NULL) {
        second = second->next;
        first = first->next;
        if(first == NULL) {
          if(prev != NULL)
            prev->next = second->next;
          else
            return second->next;
        }
        prev = second;
      }
      return head;
    }
};

int main() {
  ListNode* l1 = new ListNode(1);
  ListNode* h1 = l1;
  for(int i = 2 ; i <= 4 ; ++i) {
    l1->next = new ListNode(i);
    l1 = l1->next;
  }
  Solution s;
  h1 = s.removeNthFromEnd(h1, 4);
  while(h1 != NULL) {
    std::cout << h1->val << std::endl;
    h1 = h1->next;
  }
  return 0;
}
