/*
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};*/
class Solution {
public:
  ListNode* ReverseList(ListNode* pHead) {
    if (!pHead) return nullptr;
    ListNode *pre  = nullptr;
    ListNode *cur  = pHead;
    ListNode *next = pHead->next;
    while (cur) {
      cur->next = pre;
      pre  = cur;
      cur  = next;
      next = next->next;
    }
    return pre;
  }
};