/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
    ListNode* mergeLists(ListNode* l1, ListNode* l2) {
        if (l1 == NULL) return l2;
        if (l2 == NULL) return l1;

        if (l1->val <= l2->val) {
            l1->next = mergeLists(l1->next, l2);
            return l1;
        } else {
            l2->next = mergeLists(l1, l2->next);
            return l2;
        }
    }

    ListNode* partitionMerge(int start, int end, vector<ListNode*>& lists) {
        if (start > end) return NULL;
        if (start == end) return lists[start];
        int mid = start + (end - start) / 2;
        ListNode* L1 = partitionMerge(start, mid, lists);
        ListNode* L2 = partitionMerge(mid + 1, end, lists);

        return mergeLists(L1, L2);
    }

   public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();
        if (n == 0) return NULL;
        return partitionMerge(0, n - 1, lists);
    }
};
