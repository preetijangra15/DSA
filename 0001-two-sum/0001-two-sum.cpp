class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        int n = nums.size();
        
        vector<pair<int,int>> res;
        
//         for(int i=0;i<n;i++)
//             res.push_back({nums[i], i});
        
        
//         sort(res.begin(), res.end());
        
//         int i = 0, j = n-1;
        
//         while(i < j)
//         {
//             int s = res[i].first + res[j].first;
            
//             if(s == target)
//                 return {res[i].second, res[j].second};
//             else if(s > target)
//                 j--;
//             else
//                 i++;
//         }
        
//         return {-1,-1};
        
        for(int i = 0; i<n-1; i++)
        {
            for(int j = i+1; j<n;j++)
            {
                if(nums[i] + nums[j] == target)
                    return {i,j};
            }
        }
        
        return {-1, -1};
    }
};