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
    int longestPath(TreeNode* root, int& ans) {
        if (!root) return 0;
        if (!root->left && !root->right) return 1;
        int left = longestPath(root->left,ans);
        int right = longestPath(root->right,ans);
        ans = max(ans, left + right);
        return 1 + max(left, right);
    }

   public:
    int diameterOfBinaryTree(TreeNode* root) {
        int ans = 0;
        longestPath(root, ans);
        return ans;
    }
};
