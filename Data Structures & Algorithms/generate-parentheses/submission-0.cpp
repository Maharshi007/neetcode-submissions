class Solution {
    void parentheses(int open, int close, string &temp, vector<string>& ans) {
        if (open > close || open < 0) return;
        if (open == 0 && close == 0) {
            ans.push_back(temp);
            return;
        }
        temp.push_back('(');
        parentheses(open - 1, close, temp, ans);
        temp.pop_back();

        temp.push_back(')');
        parentheses(open, close - 1, temp, ans);
        temp.pop_back();
    }

   public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string temp;
        parentheses(n, n, temp, ans);
        return ans;
    }
};
