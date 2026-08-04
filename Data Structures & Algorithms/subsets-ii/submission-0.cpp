class Solution {
    void subsets(vector<int>& nums, int index, int n, vector<int>& temp, vector<vector<int>>& ans)
    {
        for(int i=index;i<n;i++)
        {
            if(i>index && nums[i]==nums[i-1]) continue;
            temp.push_back(nums[i]);
            ans.push_back(temp);
            subsets(nums,i+1,n,temp,ans);
            temp.pop_back();
        }
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int>temp;
        ans.push_back({});
        sort(nums.begin(),nums.end());
        subsets(nums,0,nums.size(),temp,ans);
        return ans;
    }
};
