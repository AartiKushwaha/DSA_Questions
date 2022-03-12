class Solution {
public:
    int binarySearch(vector<int>& nums, int low, int high, int target)
    {
        cout<<"Searching.... target with "<<low<<"->"<<high<<endl;
        
        while(low<=high)
        {
            int mid = low+(high-low)/2;
            
            if(target > nums[mid])
                low = mid+1;
            else if(target < nums[mid])
                high = mid-1;
            else
                return mid;
        }
        return -1;
    }
    
    int search(vector<int>& nums, int target)
    {
        if(nums.size()==0 || (nums.size()==1 && nums[0]!=target))
            return -1;
        
        if(nums.size()==1 && nums[0]==target)
            return 0;
        
        if(nums[0] < nums[nums.size()-1])
        {
            return binarySearch(nums, 0, nums.size()-1, target);
        }
        else
        {
            int vSize = nums.size();
            
            int low = 0;
            int high = vSize-1;
            
            while(low < high-1)
            {
                cout<<"Searching.... Pivot"<<endl;
                
                int mid = low+(high-low)/2;
                
                if(nums[mid] > nums[high])
                    low = mid;
                else if(nums[mid] < nums[low])
                    high = mid;
                else
                    break;
            }
            int pivot = high;
            
            cout << "Pivot : "<<pivot<<endl;
            
            if(nums[0] <= target && target <= nums[pivot-1])
                return binarySearch(nums, 0, pivot-1, target);
            else
                return binarySearch(nums, pivot, vSize-1, target);
            
        }
        return -1;
    }
};