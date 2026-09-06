class Solution {
   public:
    int numDistinct(string s, string t) {
        int n = s.size();
        int m = t.size();
        vector<unsigned long long> prev(m + 1, 0);
        vector<unsigned long long> curr(m + 1, 0);
        prev[m] = 1;
        curr[m] = 1;
        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {
                unsigned long long notTake = prev[j];
                unsigned long long take = 0;
                if (s[i] == t[j]) take = prev[j + 1];
                curr[j] = notTake + take;
            }
            prev = curr;
        }
        return prev[0];
    }
};
