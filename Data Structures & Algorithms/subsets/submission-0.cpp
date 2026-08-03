class Solution {
    void helper(vector<int>& nums,int index,int n, vector<int>temp, vector<vector<int>>& ans)
    {
        if(index == n)
        {
            ans.push_back(temp);
            return;
        }
        helper(nums,index+1,n,temp,ans);
        temp.push_back(nums[index]);
        helper(nums,index+1,n,temp,ans);
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> temp;
        vector<vector<int>> ans;
        helper(nums,0,nums.size(),temp,ans);
        return ans;
    }
};