
class Solution {
public:
    
    bool isValid(long long sum, vector<int> &nums, int m){
        long long total = 0, cnt = 1;
        for(auto num: nums){
            total += num;
            if(total > sum){
                total = num;
                cnt++;
                if(cnt > m) return false;
            }
        }
        return true;
    }
    
    int splitArray(vector<int>& nums, int m) {
        long long left = 0, right = 0;
        for(auto num: nums){
            left = max(left, (long long)num);
            right += num;
        }
        if(m==1) return right;
        while(left<=right){
            long long mid = (right+left)/2;
            if(isValid(mid,nums,m)) right = mid-1;
            else left = mid+1;
        }
        return left;
    }
};