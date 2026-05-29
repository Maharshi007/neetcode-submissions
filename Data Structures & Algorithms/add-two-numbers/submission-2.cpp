class Solution {
   private:
    int getLength(ListNode* head) {
        int len = 0;
        while (head) {
            len++;
            head = head->next;
        }
        return len;
    }
   public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int len1 = getLength(l1);
        int len2 = getLength(l2);
        if (len2 > len1) {
            swap(l1, l2);
        }
        ListNode* curr1 = l1;
        ListNode* curr2 = l2;
        ListNode* tail = nullptr;
        int carry = 0;
        while (curr1 || carry) {
            if (!curr1) {
                tail->next = new ListNode(0);
                curr1 = tail->next;
            }
            int sum = curr1->val + carry;
            if (curr2) {
                sum += curr2->val;
                curr2 = curr2->next;
            }
            curr1->val = sum % 10;
            carry = sum / 10;
            tail = curr1;
            curr1 = curr1->next;
        }
        return l1;
    }
};