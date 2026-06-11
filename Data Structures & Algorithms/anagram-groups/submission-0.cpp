class Solution {
   public:
    string generate(string& word) {
        int arr[26] = {0};
        string newWord = "";
        for (int i = 0; i < word.size(); i++) {
            arr[word[i] - 'a']++;
        }
        for (int i = 0; i < 26; i++) {
            int freq = arr[i];
            if (freq) {
                newWord += string(freq, i + 'a');
            }
        }
        return newWord;
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        unordered_map<string, vector<string>> mpp;
        for (int i = 0; i < strs.size(); i++) {
            string word = strs[i];
            string newWord = generate(word);
            mpp[newWord].push_back(word);
        }
        for (auto it : mpp) ans.push_back(it.second);
        return ans;
    }
};