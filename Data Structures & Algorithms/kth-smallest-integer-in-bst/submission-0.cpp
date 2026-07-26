/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        int cnt = 0;
        TreeNode* curr = root;
        while(curr)
        {
            if(!curr ->left)
            {
                cnt++;
                if(cnt == k) return curr->val;
                curr = curr -> right;
            }
            else
            {
                TreeNode* LC = curr -> left;
                while(LC -> right)
                {
                    LC = LC -> right;
                }
                LC -> right = curr;
                TreeNode* temp = curr;
                curr = curr -> left;
                temp -> left = NULL;
            }
        }
        return cnt;
    }
};
