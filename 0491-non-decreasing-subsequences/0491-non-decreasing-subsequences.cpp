class Solution {
public:
    set<vector<int>> ans;
    
    void solve(vector<int> &nums, int n, int i, vector<int> &v)
    {
        if(i == n)
        {
            int x = v.size();
            if(x<2)
                return;
            
            for(int j = 0;j+1<x;j++)
            {
                if(v[j] > v[j+1])
                    return;
            }
            
            ans.insert(v);
            return;
        }
        
        vector<int> v1 = v;
        vector<int> v2 = v;
        v2.push_back(nums[i]);
        
        solve(nums,n,i+1,v1);
        solve(nums,n,i+1,v2);
        
    }
    
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        //sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<vector<int>> res;
        vector<int> v;
        solve(nums,n,0,v);
        
        for(auto x:ans)
        {
            res.push_back(x);
        }
        return res;
    }
};