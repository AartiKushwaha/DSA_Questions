//Trapping Rain Water

int trap(vector<int>& height) {
        
    int n = height.size(); 
    int left=0; int right=n-1;
    int res=0;
    int maxleft=0, maxright=0;
    
    while(left<=right){
        
        if(height[left]<=height[right]){

            if(height[left]>=maxleft) maxleft=height[left];
            else res+=maxleft-height[left];
            
            left++;
        }
        else{

            if(height[right]>=maxright) maxright= height[right];
            else res+=maxright-height[right];
            
            right--;
        }
    }
    return res;
}


// 3 Sum


vector<vector<int>> threeSum(vector<int>& nums) {
        int n=nums.size();
        if(n<3) return {};
                sort(nums.begin(),nums.end());
                vector<vector<int>> ans;
                for(int i=0;i<n-2;i++){
                    if(i==0 || nums[i]!=nums[i-1]){
                        int j=i+1,k=n-1;
                        while(j<k){
                            int sum=nums[i]+nums[j]+nums[k];
                            if(sum==0){
                                ans.push_back({nums[i],nums[j],nums[k]});
                                while(j<k && nums[j]==nums[j+1]) j++;
                                while(j<k && nums[k]==nums[k-1]) k--;
                                j++;k--;
                            }else if(sum<0) j++;
                            else k--;
                        }
                    }
                }
        return ans;
        }
