class Solution {
   public:
    string minWindow(string s, string t) {
        int n = s.size();
        int m = t.size();
        if (m > n) return "";
        int left = 0, minLen = 1e9, sIdx = -1, cnt = 0;
        vector<int> freqs(256, 0);
        vector<int> freqt(256, 0);
        for (auto& ch : t) freqt[(unsigned char)ch]++;
        for (int right = 0; right < n; right++) {
            char ch = s[right];
            freqs[(unsigned char)ch]++;
            if (freqs[(unsigned char)ch] <= freqt[(unsigned char)ch]) cnt++;
            while (cnt == m) {
                if ((right - left + 1) < minLen) {
                    minLen = (right - left + 1);
                    sIdx = left;
                }
                char ch1 = s[left];
                if (freqs[(unsigned char)ch1] <= freqt[(unsigned char)ch1]) cnt--;
                freqs[(unsigned char)ch1]--;
                left++;
            }
        }
        if (sIdx == -1) return "";
        return s.substr(sIdx, minLen);
    }
};
