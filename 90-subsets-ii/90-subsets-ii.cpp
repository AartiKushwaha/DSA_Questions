class Solution {
public:
    
    void solver(vector<int>& nums, int idx, set<vector<int>> &Set, vector<int> temp){
        
        if(idx>=nums.size()){
            sort(temp.begin(), temp.end());
            Set.insert(temp);
            return;
        }
        temp.push_back(nums[idx]);
        solver(nums, idx+1, Set, temp);
        temp.pop_back();
        solver(nums, idx+1, Set, temp);
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        set<vector<int>> Set;
        vector<int> temp;
        solver(nums, 0, Set, temp);
        for(auto it: Set) ans.push_back(it);
        return ans;
    }
};