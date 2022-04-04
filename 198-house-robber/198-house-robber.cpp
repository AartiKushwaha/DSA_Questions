class Solution {
public:
    
    int solver(int idx, vector<int>& nums, vector<int> &dp){
        if(idx == 0) return nums[idx];
        if(idx < 0) return 0;
        
        if(dp[idx] != -1) return dp[idx];
        
        int rob = nums[idx] + solver(idx-2, nums, dp);
        int dont = 0 + solver(idx-1, nums, dp);
        return dp[idx] = max(rob, dont);
    }
    
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1);
        return solver(n-1, nums, dp);
    }
};