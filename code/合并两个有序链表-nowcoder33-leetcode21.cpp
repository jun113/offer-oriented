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
  ListNode* Merge(ListNode* pHead1, ListNode* pHead2) {
    if (!pHead1 && !pHead2) return nullptr;
    if (!pHead1) return pHead2;
    if (!pHead2) return pHead1;

    ListNode *result;
    result = myMergeListNodeNotRecursion(pHead1, pHead2);
    return result;
  }
private:
  // 非递归实现
  ListNode* myMergeListNodeNotRecursion(ListNode *list1, ListNode *list2) {
    ListNode *dummy = new ListNode(0);
    ListNode *cur = dummy;
    while (list1 && list2) {
      if (list1->val < list2->val) {
        cur->next = list1;
        list1 = list1->next;
      } else {
        cur->next = list2;
        list2 = list2->next;
      }
      cur = cur->next;
    }
    if (list1) cur->next = list1;
    if (list2) cur->next = list2;
    return dummy->next;
  }
  // 递归实现
  ListNode * myMergeListNodeRecursion(ListNode *list1, ListNode *list2) {
    if(!list1) return list2;
    if(!list2) return list1;
    if (list1-> val < list2->val) {
      list1->next = myMergeListNodeRecursion(list1->next, list2);
      return list1;
    } else {
      list2->next = myMergeListNodeRecursion(list1, list2->next);
      return list2;
    }
  }
};