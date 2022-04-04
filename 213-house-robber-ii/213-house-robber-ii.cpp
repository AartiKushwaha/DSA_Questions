class Solution {
public:
    
    int fun(vector<int>& nums, int s, int e) {
        int prev = nums[s];
        int prev2 = 0;
        for(int i=s+1; i<=e; i++){
            int rob = nums[i];
            if(i>1) rob+=prev2;
            int dont = prev;
            int curr = max(rob, dont);
            prev2 = prev;
            prev = curr;
        }
        return prev;
    }
    
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return nums[0];
        if(n==2) return (nums[0]>nums[1])?nums[0]:nums[1];
        int first = fun(nums, 0, n-2);
        int sec = fun(nums, 1, n-1);
        return max(first, sec);
    }
};