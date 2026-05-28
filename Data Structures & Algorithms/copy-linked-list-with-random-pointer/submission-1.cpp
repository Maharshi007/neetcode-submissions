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
    void insertNewNodes(Node* head) {
        Node* temp = head;
        while (temp) {
            Node* newNode = new Node(temp->val);
            newNode->next = temp->next;
            temp->next = newNode;
            temp = temp->next->next;
        }
    }

    void connectRandomPtr(Node* head) {
        Node* temp = head;
        while (temp) {
            if (temp->random == NULL)
                temp->next->random = NULL;
            else
                temp->next->random = temp->random->next;
            temp = temp->next->next;
        }
    }
    Node* getNewList(Node* head) {
        Node* temp = head;
        Node* dummy = new Node(-1);
        Node* res = dummy;
        while (temp) {
            res->next = temp->next;
            res = res->next;
            temp->next = res -> next;
            temp = temp->next;
        }
        Node* newHead = dummy;
        newHead = newHead->next;
        delete dummy;
        return newHead;
    }

   public:
    Node* copyRandomList(Node* head) {
        if (head == NULL) return head;
        // INSERT NEW NODES IN BETWEEN ORIGINAL NODES
        insertNewNodes(head);
        // CONNECT THE RANDOM POINTERS
        connectRandomPtr(head);
        // REMOVE THE CONNECTION BETWEEN ORIGINAL & NEW NODES AND MAKE THE ORIGINAL LIST AS IT IS
        return getNewList(head);
    }
};
