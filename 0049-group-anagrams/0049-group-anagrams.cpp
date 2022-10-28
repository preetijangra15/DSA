class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        vector<vector<string>> ans;
        //vector<string> res;
        
        int n = strs.size();
        // for(int i=0;i<n;i++)
        // {
        //     string s = strs[i];
        //     sort(s.begin(), s.end());
        //     res.push_back(s);
        // }
        
        unordered_map<string, vector<string> > mp;
        
        for(int i=0;i<n;i++)
        {
            // mp[res[i]]++;
            
            string str = strs[i];
            sort(str.begin(), str.end());
            
            mp[str].push_back(strs[i]);
        }
        
        for(auto x : mp)
        {
            //cout<<x.first<<endl;
            vector<string> v = x.second;
            ans.push_back(v);
        }
        
//         for(auto x:mp)
//             cout<<x.first<<" "<<x.second<<endl;
//         int len = mp.size();
//         vector<vector<string>> v(len);
//         for(int i=0;i<n;i++)
//         {
//             int count =0;
            
//             for(auto x:mp)
//             {
//                 //cout<<res[i]<<" "<<x.first<<endl;
//                 if(res[i] == x.first)
//                 {
//                     cout<<res[i]<<" entering if "<<strs[i]<<endl;
//                     v[count].push_back(strs[i]);
//                 }
//                 count++;
//             }

//         }
        return ans;
    }
};