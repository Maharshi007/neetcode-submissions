class Solution {
   public:
    string minWindow(string s, string t) {
        int n = s.size();
        int m = t.size();
        if (m > n) return "";
        int left = 0, minLen = 1e9, sIdx = -1, cnt = 0;
        vector<int> freq(256, 0);
        for (char& ch : t) {
            freq[(unsigned char)ch]++;
        }
        for (int right = 0; right < n; right++) {
            char ch = s[right];
            if (freq[(unsigned char)ch] > 0) cnt++;
            freq[(unsigned char)ch]--;
            while (cnt == m) {
                if ((right - left + 1) <= minLen) {
                    minLen = right - left + 1;
                    sIdx = left;
                }
                char ch1 = s[left];
                freq[(unsigned char)ch1]++;
                if (freq[(unsigned char)ch1] > 0) cnt--;
                left++;
            }
        }
        if (sIdx == -1) return "";
        return s.substr(sIdx, minLen);
    }
};
