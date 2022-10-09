class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
        vector<int> v;
        int i = 0, j = 0;
        int n = nums1.size(), m = nums2.size();
        
        while( i < n && j < m)
        {
            if( nums1[i] < nums2[j])
            {
                v.push_back(nums1[i]);
                i++;
            }
            else if( nums1[i] > nums2[j])
            {
                v.push_back(nums2[j]);
                j++;
            }
            else{
                v.push_back(nums1[i]);
                v.push_back(nums2[j]);
                i++; 
                j++;
            }
        }
        
        while( i < n)
        {
            v.push_back(nums1[i]);
            i++;
        }
        
        while(j < m)
        {
            v.push_back(nums2[j]);
            j++;
        }
        
        float ans;
        cout<<(m+n)/2<<endl;
        
        for(auto x:v)
            cout<<x<<" ";
        
        if( (m+n)%2 != 0)
            return float(v[(m+n)/2]);
        
        float a = float(v[(m+n)/2]);
        float b = float(v[(m+n)/2 - 1]);
        
        cout<<endl;
        cout<<"a/b ";
        cout<<a<<" "<<b<<endl;
        
        return (a+b)/2;
    }
};