class Solution {
public:
    bool binarySearch(vector<int>& nums, int left, int right, int t){
        if(left > right) return false;
        int mid = (left+right)/2;
        if(nums[mid] == t) return true;
        if(nums[mid] > t) return binarySearch(nums, left, mid-1, t);
        if(nums[mid] < t) return binarySearch(nums, mid+1, right, t);
        return false;
    }
    bool search(vector<int>& nums, int target) {
        int i = 0;
        int n = nums.size();
        int pivot = -1;
        while(i < n-1){
            if(nums[i+1] < nums[i]){
                pivot = i+1;
                break;
            }
            i++;
        }
        if(pivot == -1){
            return binarySearch(nums,0,n-1,target);
        }
        else{
            if(nums[pivot] == target) return true;
            if(pivot+1 < n and nums[pivot+1] <= target and nums[n-1] >= target){
                return binarySearch(nums, pivot+1, n-1, target);
            }
            else if(pivot-1 >= 0 and nums[0] <= target and nums[pivot-1] >= target) {
                return binarySearch(nums, 0, pivot-1, target);
            }
            else return false;
        }
        return true;
    }
};