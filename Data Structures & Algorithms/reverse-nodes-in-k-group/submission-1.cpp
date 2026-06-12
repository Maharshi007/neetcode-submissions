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
    ListNode* reverse(ListNode* head) {
        if (head == nullptr) return head;
        ListNode* curr = head;
        ListNode* prev = nullptr;
        ListNode* front;
        while (curr) {
            front = curr->next;
            curr->next = prev;
            prev = curr;
            curr = front;
        }
        return prev;
    }
    ListNode* findKthNode(ListNode* head, int k) {
        ListNode* temp = head;
        while (temp && --k) {
            temp = temp->next;
        }
        return temp;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        ListNode* kthNode;
        ListNode* prevNode = nullptr;
        ListNode* nextNode;
        while (temp) {
            kthNode = findKthNode(temp, k);
            if (kthNode == NULL) {
                if (prevNode) prevNode->next = temp;
                break;
            }

            nextNode = kthNode->next;
            kthNode->next = nullptr;
            reverse(temp);
            if (head == temp)
                head = kthNode;
            else {
                prevNode->next = kthNode;
            }
            prevNode = temp;
            temp = nextNode;
        }
        return head;
    }
};
