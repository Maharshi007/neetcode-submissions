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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* tail = head;
        ListNode *t1 = NULL, *t2 = head;
        int len = 0;
        while (tail) {
            len++;
            tail = tail->next;
        }
        if (len == n) {
            ListNode* temp = head;
            head = head->next;
            delete temp;
            return head;
        }
        int deleteNode = len - n;
        int cnt = 1;
        while (t2) {
            if (cnt == deleteNode) {
                ListNode* t1 = t2->next;
                t2->next = t1->next;
                delete t1;
                break;
            }
            cnt++;
            t2 = t2->next;
        }
        
        return head;
    }
};
