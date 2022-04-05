class Solution {
public:
    int maxArea(vector<int>& arr) {
        int n = arr.size();
        int i=0, j = n-1, area=INT_MIN;
        while(i<j){
            int width = j-i;
            int ht = min(arr[i], arr[j]);
            area = max(area, width*ht);
            if(arr[i]<arr[j]) i++;
            else j--;
        }
        return area;
    }
};