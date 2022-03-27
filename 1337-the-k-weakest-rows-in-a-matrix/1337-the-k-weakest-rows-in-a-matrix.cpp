class Solution {
public:
    
    int countOnes(vector<int> nums){
        int n = nums.size();
        int low = 0, high = n-1;
        int ans=-1;
        while(low<=high){
            int mid = high - (high-low)/2;
            if(nums[mid]>0){
                low = mid+1;
            }
            else{
                ans = mid;
                high = mid-1;
            }
        }
        if(ans==-1) return n;
        else return ans;
    }
    
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        set<pair<int, int>> m;
        for (int i = 0; i < mat.size(); ++i) {
            int p = countOnes(mat[i]);
            m.insert({p, i});
        }
        vector<int> res;
        for (auto it = begin(m); k > 0; ++it, --k)
            res.push_back(it->second);
        return res;
    }
};