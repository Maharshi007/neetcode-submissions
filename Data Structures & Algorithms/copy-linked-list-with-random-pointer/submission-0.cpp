/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
   public:
    Node* copyRandomList(Node* head) {
        if (head == NULL) return head;
        unordered_map<Node*, Node*> mpp;
        Node* tail = head;
        while (tail) {
            mpp[tail] = new Node(tail->val);
            tail = tail->next;
        }
        tail = head;
        while (tail) {
        mpp[tail]->next = mpp[tail -> next];
        mpp[tail] -> random = mpp[tail -> random];
        tail = tail -> next;    
        }
        tail = head;
        return mpp[tail];
    }
};
