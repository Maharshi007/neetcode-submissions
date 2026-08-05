class Solution {
    bool isPalindrome(string& s, int left, int right) {
        while (left < right) {
            if (s[left] != s[right]) return false;
            left++;
            right--;
        }
        return true;
    }
    void helper(string& s, int idx, int n, vector<string>& temp, vector<vector<string>>& ans) {
        if (idx == n) {
            ans.push_back(temp);
            return;
        }
        for (int i = idx; i < n; i++) {
            if (isPalindrome(s, idx, i)) {
                temp.push_back(s.substr(idx, i - idx + 1));
                helper(s, i + 1, n, temp, ans);
                temp.pop_back();
            }
        }
    }

   public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> temp;
        int n = s.size();
        helper(s, 0, n, temp, ans);
        return ans;
    }
};
