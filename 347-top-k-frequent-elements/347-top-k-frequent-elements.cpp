class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        vector<int> ans;
        for(int it:nums){
            mp[it]++;
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> minh;
        for(auto i=mp.begin();i!=mp.end();i++){
            minh.push(make_pair(i->second, i->first));
            if(minh.size()>k){
                minh.pop();
            }
        }
        while(!minh.empty()){
            ans.push_back(minh.top().second);
            minh.pop();
        }
        return ans;
    }
};