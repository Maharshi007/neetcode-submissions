class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_map<int,int> mpp;
        for(int& it : nums){
            if(mpp.find(it) != mpp.end()){
                if(mpp[it]) return true;
            }
            mpp[it]++;
        }
        return false;
    }
};