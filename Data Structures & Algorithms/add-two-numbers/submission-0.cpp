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
    int length(ListNode* head) {
        int cnt = 0;
        while(head) {
            cnt++;
            head = head->next;
        }
        return cnt;
    }
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int len1 = length(l1);
        int len2 = length(l2);
        if(len2 > len1) {
            swap(l1, l2);
        }
        ListNode* temp1 = l1;
        ListNode* temp2 = l2;
        ListNode* prev = NULL;
        int carry = 0;
        while(temp1 && temp2) {
            int sum = carry + temp1->val + temp2->val;
            temp1->val = sum % 10;
            carry = sum / 10;
            prev = temp1;
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        while(temp1) {
            int sum = carry + temp1->val;
            temp1->val = sum % 10;
            carry = sum / 10;
            prev = temp1;
            temp1 = temp1->next;
        }
        if(carry) {
            prev->next = new ListNode(carry);
        }
        return l1;
    }
};