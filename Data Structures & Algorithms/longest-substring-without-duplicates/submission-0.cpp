class Solution {
   public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        vector<int> freq(256, 0);
        int left = 0, right = 0;
        int maxi = 0;
        for (int right = 0; right < n; right++) {
            while (freq[s[right]] > 0) {
                freq[s[left]]--;
                left++;
            }

            freq[s[right]]++;

            maxi = max(maxi, right - left + 1);
        }

        return maxi;
    }
};
