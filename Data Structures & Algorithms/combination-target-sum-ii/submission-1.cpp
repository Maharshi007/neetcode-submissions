class Solution {
    void findCombination(vector<int>& candidates,int index,int n,int target,vector<int>& temp,vector<vector<int>>& ans)
    {
        if(target == 0)
        {
            ans.push_back(temp);
            return;
        }
        if(target<0) return;
        for(int i=index;i<n;i++)
        {
            if(i>index && candidates[i]==candidates[i-1]) continue;
            if(candidates[i]>target) break;
            temp.push_back(candidates[i]);
            findCombination(candidates,i+1,n,target-candidates[i],temp,ans);
            temp.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        sort(candidates.begin(),candidates.end());
        findCombination(candidates,0,candidates.size(),target,temp,ans);
        return ans;
    }
};
