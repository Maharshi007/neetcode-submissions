class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int>p;
        for(int it:stones)
        p.push(it);
        while(p.size()>1)
        {
            int ans = p.top();
            p.pop();
            ans-=p.top();
            p.pop();
            if(ans) p.push(ans);
        }
        return p.empty() ? 0 : p.top();
    }
};
