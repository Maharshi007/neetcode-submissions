class Solution {
   public:
    bool isAnagram(string s, string t) {
        int n = s.size(), m = t.size();
        if(n != m) return false;
        vector<int> freq1(26, 0);
        vector<int> freq2(26, 0);
        int i = 0, j = 0;
        while (i < n || j < m) {
            if (i < n) {
                char ch1 = s[i] - 'a';
                freq1[ch1]++;
                i++;
            }
            if (j < m) {
                char ch2 = t[j] - 'a';
                freq2[ch2]++;
                j++;
            }
        }
        return freq1 == freq2;
    }
};
