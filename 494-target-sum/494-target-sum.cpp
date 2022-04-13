class Solution {
public:
    
    int solver(vector<int>& nums, int target, int idx){
        if(target==0 and idx==nums.size()) return 1;
        if(idx>=nums.size()) return 0;
        
        int plus = solver(nums, target-nums[idx], idx+1);
        int minus = solver(nums, target+nums[idx], idx+1);
        
        return (plus+minus);
    }
    
    int findTargetSumWays(vector<int>& nums, int target) {
        return solver(nums, target, 0);
    }
};