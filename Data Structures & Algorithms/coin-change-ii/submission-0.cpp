class Solution {
   public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<int> prev(amount + 1, 0), curr(amount + 1, 0);
        prev[0] = 1;
        for (int i = n - 1; i >= 0; i--) {
            fill(curr.begin(), curr.end(), 0);
            curr[0] = 1;
            for (int j = 1; j <= amount; j++) {
                long long skip = prev[j];
                long long take = 0;
                if (j >= coins[i]) {
                    take = curr[j - coins[i]];
                }
                curr[j] = skip + take;
            }
            prev = curr;
        }
        return (int)prev[amount];
    }
};