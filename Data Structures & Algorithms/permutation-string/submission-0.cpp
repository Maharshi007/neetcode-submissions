class Solution {
   public:
    int allZeroes(vector<int>& count) {
        for (int& it : count) {
            if (it) return false;
        }
        return true;
    }
    bool checkInclusion(string pat, string txt) {
        int k = pat.size();
        int n = txt.size();
        vector<int> count(26, 0);
        for (char& ch : pat) {
            count[ch - 'a']++;
        }
        int left = 0, right = 0;
        while (right < n) {
            count[txt[right] - 'a']--;
            if ((right - left + 1) == k) {
                if (allZeroes(count)) return true;
                count[txt[left] - 'a']++;
                left++;
            }
            right++;
        }
        return false;
    }
};
