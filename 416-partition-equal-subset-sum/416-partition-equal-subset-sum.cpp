class Solution {
public:
    
    bool solver(int idx, int target, vector<int> &arr, vector<vector<int>> &dp){
        if(target==0) return true;
        if(idx==0) return (arr[0]==target);
        if(dp[idx][target] != -1) return dp[idx][target];
        bool notTake = solver(idx-1, target, arr, dp);
        bool take = false;
        if(target >= arr[idx]){
            take = solver(idx-1, target - arr[idx], arr, dp);
        }
        
        return dp[idx][target] = (notTake or take);
    }
    
    bool canPartition(vector<int>& nums) {
        
        int sum = 0;
        for(auto num: nums) sum+=num;
        int n = nums.size();
        if(sum%2==1) return false;
        vector<vector<int>> dp(n, vector<int>(sum/2 + 1, -1));
        return solver(nums.size()-1, sum/2, nums, dp);
    }
};