class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {

        vector<int> ans;

        if (!root)
            return ans;

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {

            int size = q.size();

            while (size--) {

                TreeNode* node = q.front();
                q.pop();

                // Last node of this level
                if (size == 0)
                    ans.push_back(node->val);

                if (node->left)
                    q.push(node->left);

                if (node->right)
                    q.push(node->right);
            }
        }

        return ans;
    }
};