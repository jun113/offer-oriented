/*
  nowcoder id: 50
*/
/**
 * struct ListNode {
 *	int val;
 *	struct ListNode *next;
 * };
 */

class Solution {
public:
    /**
     *
     * @param head ListNode
     * @param k int
     * @return ListNode
     */
  ListNode* reverseKGroup(ListNode* head, int k) {
    if (!head || k<2) return head;
    ListNode *result = myreverseKGroupRecursion(head, k);
    return result;
  }
 private:
  ListNode* myreverseKGroupRecursion(ListNode* head, int k) {
    if(!head || k <= 1) return head;
    ListNode *pre = nullptr;
    ListNode *cur = head;
    ListNode *next = nullptr;
    for (int i = 0; i < k; ++i) {
      if(!cur) return head;
      cur = cur->next;
    }
    cur = head;
    for (int i = 0; i < k; ++i) {
      next = cur->next;
      cur->next = pre;
      pre = cur;
      cur = next;
    }
    head->next = myreverseKGroupRecursion(next, k);
    return pre;
  }
};