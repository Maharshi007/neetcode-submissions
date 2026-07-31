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
    int ans = INT_MIN;
    int pathSum(TreeNode* root)
    {
        if(!root) return 0;
        int left = max(0, pathSum(root->left));
        int right = max(0, pathSum(root->right));
        ans = max(ans, left + right + root->val);
        return root->val + max(left, right);
    }
public:
    int maxPathSum(TreeNode* root) {
        pathSum(root);
        return ans;
    }
};
