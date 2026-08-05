class Solution {
    void permutation(vector<int>& nums,int index,vector<vector<int>>& ans)
    {
        if(index == nums.size())
        {
            ans.push_back(nums);
            return;
        }
        for(int i=index;i<nums.size();i++)
        {
            swap(nums[i],nums[index]);
            permutation(nums,index+1,ans);
            swap(nums[i],nums[index]);
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        permutation(nums,0,ans);
        return ans;
    }
};
