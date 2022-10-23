class Solution {
public:
    
    void cyclicsort(vector<int>& nums)
    {
        int n = nums.size();
        int i=0;
        while(i<n)
        {
            int correct = nums[i]-1;
            if(nums[i]!=nums[correct])
                swap(nums[i], nums[correct]);
            else 
                i++;
        }
    }
    vector<int> findErrorNums(vector<int>& nums) {
        // sort(nums.begin(), nums.end());
         int n= nums.size();
         vector<int> v;
        // for(int i=0;i<n;i++)
        // {
        //     if(nums[i] != i+1)
        //     {
        //         v.push_back(nums[i]);
        //         v.push_back(i+1);
        //     }
        // }
        
        cyclicsort(nums);
        for(auto x:nums)
            cout<<x<<" ";
        
        for(int i=0;i<n;i++)
        {
            if(nums[i]!=i+1)
            {
                v.push_back(nums[i]);
                v.push_back(i+1);
            }
        }
        
        return v;
    }
};