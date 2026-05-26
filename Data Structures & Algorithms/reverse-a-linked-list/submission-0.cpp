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
   public:
    ListNode* reverseList(ListNode* head) {
        if (head == NULL || head->next == NULL) return head;
        struct ListNode* prev = NULL;
        struct ListNode* t1 = head;
        struct ListNode* t2 = head->next;
        while (t2) {
            prev = t1;
            t1 = t2;
            t2 = t2 -> next;
            t1 -> next = prev;
        }
        head -> next = NULL;
        return t1;
    }
};
