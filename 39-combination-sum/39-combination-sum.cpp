class Solution {
public:
    
    void solver(int idx, int target, vector<int>& arr, vector<vector<int>>& ans, vector<int>& v){
        if(idx==arr.size()){
            if(target==0){
                ans.push_back(v);
            }
            return;
        }
        if(arr[idx]<=target){
            v.push_back(arr[idx]);
            solver(idx, target-arr[idx], arr, ans, v);
            v.pop_back();
            
        }
        solver(idx+1, target, arr, ans, v);
    }
    
    
    vector<vector<int>> combinationSum(vector<int>& arr, int target) {
        vector<vector<int>> ans;
        vector<int> v;
        solver(0, target, arr, ans, v);
        return ans;
    }
};