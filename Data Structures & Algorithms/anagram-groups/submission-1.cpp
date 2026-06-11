// APPROACH -1
// Sort each word, so it's anagaram fall into same family.
// Store them in MAP and iterate until strs is over
// Now iterate over the MAP and store the family in ans vector and return it
// TC : O(NKLOGK)
// SC : O(N);
class Solution {
   public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mpp;
        vector<vector<string>> ans;
        for (auto& it : strs) {
            string temp = it;
            sort(temp.begin(), temp.end());
            mpp[temp].push_back(it);
        }
        for (auto& it : mpp) {
            ans.push_back(it.second);
        }
        return ans;
    }
};