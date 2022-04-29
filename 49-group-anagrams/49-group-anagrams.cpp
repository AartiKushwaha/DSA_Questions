class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n = strs.size();
        vector<vector<string>> ans;
        map<string, vector<int>> mp;
        for(int i=0; i<n; i++){
            string st = strs[i];
            sort(st.begin(), st.end());
            mp[st].push_back(i);
        }
        for(auto it: mp){
            vector<int> vec = it.second;
            vector<string> s;
            for(auto i: vec) s.push_back(strs[i]);
            ans.push_back(s);
        }
        return ans;
    }
};