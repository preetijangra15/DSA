class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        int low = 0, high = n-1;
        
        if(n==1)
            return 0;
        while(low<=high)
        {
            int mid = low + (high-low)/2;
            int prev = (mid+n-1)%n;
            int next = (mid+1)%n;
            
            
            if(mid>0 && mid<n-1)
            {
                    if(nums[mid] > nums[next] && nums[mid] > nums[prev])
                {
                    int res = nums[mid];
                    return mid;
                }


                else if(nums[next]>nums[mid])
                {
                    low = mid+1;
                }

                else
                {
                    high = mid-1;
                }
            }
            
            else if(mid ==0)
            {
                if (nums[0]>nums[1])
                    return 0;
                else
                    return 1;
            }
            
            else{
                if (nums[n-1]>nums[n-2])
                    return n-1;
                else
                    return n-2;
            }
        }
        
        return -1;
    }
};