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
      if(head->next == NULL) return NULL;
      std::stack<ListNode*> stk;
      ListNode* item = head;
      ListNode* prev = NULL;
      while(item != NULL) {
        stk.push(item);
        item = item->next;
      }
      while(!stk.empty()) {
        --n;
        if(n == 0) {
          stk.pop();
          if(!stk.empty()){ 
            ListNode* left = stk.top();
            left->next = prev;
            break;
          }
          else {
            head = prev;
            return head;
          }
        } else {
          prev = stk.top();
          stk.pop();
        }
      }     
 
      return head;
    }
};

int main() {
  Solution s;
  ListNode* l1 = new ListNode(1);
  ListNode* h1 = l1;
  for(int i = 2 ; i <= 2 ; ++i) {
    l1->next = new ListNode(i);
    l1 = l1->next;
  }
  h1 = s.removeNthFromEnd(h1, 2);
  while(h1 != NULL) {
    std::cout << h1->val << std::endl;
    h1 = h1->next;
  }
  return 0;
}
