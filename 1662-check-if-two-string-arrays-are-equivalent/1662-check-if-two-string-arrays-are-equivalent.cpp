class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        
        string s = "";
        string s1 = "";
        
        int n = word1.size();
        int n1 = word2.size();
        
        for(int i = 0; i<n;i++)
            s += word1[i];
        
        for(int i = 0;i<n1;i++)
            s1 += word2[i];
        
        if(s == s1)
            return true;
        
        return false;
    }
};