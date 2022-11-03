class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0)
            return false;
        
        vector<int> v;
        while(x!=0)
        {
            v.push_back(x%10);
            x = x/10;
        }
        
        int n = v.size();
        
        for(int i=0;i<n;i++)
        {
            cout<<v[i]<<" ";
        }
        for(int i=0, j=n-1; i<n/2, j>=n/2; i++, j--)
        {
            if(v[i] != v[j])
                return false;
        }
        return true;
    }
};