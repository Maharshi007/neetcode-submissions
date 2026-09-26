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
    int dfs(TreeNode* root, int& ans) {
        if (!root) return 0;
        int left = dfs(root->left, ans);
        int right = dfs(root->right, ans);
        int leftrightroot = left + right + root->val;
        int leftOrRight = max(left, right) + root->val;
        int onlyRoot = root->val;
        ans = max({leftrightroot, leftOrRight, onlyRoot, ans});
        return max(onlyRoot, leftOrRight);
    }
    int maxPathSum(TreeNode* root) {
        int ans = -1e9;
        dfs(root, ans);
        return ans;
    }
};
