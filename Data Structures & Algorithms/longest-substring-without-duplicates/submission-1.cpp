class Solution {
   public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        vector<int> freq(256, 0);
        int left = 0, right = 0;
        int maxi = 0;
        while (right < n) {
            while (freq[s[right]]) {
                freq[s[left]] = 0;
                left++;
            }
            freq[s[right]]++;
            right++;
            maxi = max(maxi, right - left);
        }

        return maxi;
    }
};
