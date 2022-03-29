class Solution {
public:
    int findDuplicate(vector<int>& arr) {
        int dp;
        for(int i=0;i<arr.size();i++){
            if(arr[abs(arr[i])-1] < 0) dp = abs(arr[i]);
            else arr[abs(arr[i])-1] = 0 - arr[abs(arr[i])-1];
        }
        return dp;
    }
};