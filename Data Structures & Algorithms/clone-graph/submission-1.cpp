/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
   public:
    Node* cloneGraph(Node* node) {
        if (!node) return node;
        unordered_map<Node*, Node*> mpp;
        queue<Node*> q;
        mpp[node] = new Node(node->val);
        q.push(node);
        while (!q.empty()) {
            Node* v = q.front();
            q.pop();
            for (auto& adjacent : v->neighbors) {
                if (mpp.find(adjacent) == mpp.end()) {
                    mpp[adjacent] = new Node(adjacent->val);
                    q.push(adjacent);
                }
                mpp[v]->neighbors.push_back(mpp[adjacent]);
            }
        }
        return mpp[node];
    }
};
