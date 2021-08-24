/*
  nowcoder id: 4
*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
 public:
  bool hasCycle(ListNode *head) {
    if (!head || !head->next) return false;
    if (head == head->next) return true;
    bool result;
    myHasCycle(head, result);
    return result;
  }
 private:
  void myHasCycle(ListNode *head, bool &ans) {
    ListNode *slow = head;
    ListNode *fast = head->next;
    while (fast->next && fast->next->next) {
      if (slow == fast) {
        ans = true;
        return ;
      }
      slow = slow->next;
      fast = fast->next->next;
    }
    ans = false;
    return ;
  }
};