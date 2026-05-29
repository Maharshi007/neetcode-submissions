class Solution {
    ListNode* getKthNode(ListNode* head, int k) {
        int cnt = 1;
        while (head && cnt < k) {
            head = head->next;
            cnt++;
        }
        return head;
    }
    ListNode* reverse(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* curr = head;
        while (curr) {
            ListNode* front = curr->next;
            curr->next = prev;
            prev = curr;
            curr = front;
        }
        return prev;
    }
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        ListNode* prevNode = NULL;
        while (temp) {
            ListNode* KthNode = getKthNode(temp, k);
            if (KthNode == NULL) {
                if (prevNode)
                    prevNode->next = temp;
                break;
            }
            ListNode* nextNode = KthNode->next;
            KthNode->next = NULL;
            ListNode* newHead = reverse(temp);
            if (temp == head)
                head = newHead;
            else
                prevNode->next = newHead;
            temp->next = nextNode;
            prevNode = temp;
            temp = nextNode;
        }
        return head;
    }
};