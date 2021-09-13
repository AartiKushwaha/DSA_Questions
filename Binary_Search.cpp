//median in a row wise sorted matrix

/*
The idea is: Median is the middle element below which every element is smaller and bigger above it.
*/
int countSmaller(vector<int> &arr, int key){
      int low = 0, high = arr.size()-1;
      while(low<=high){
          int mid = (low+high)>>1;
          if(arr[mid]<=key) low = mid+1;
          else high = mid-1;
      }
      return low;
  }
  int median(vector<vector<int>> &matrix, int r, int c){
      int low = INT_MIN;
      int high = INT_MAX;
      while(low<=high){
          int mid = (low+high)>>1;
          int cnt=0;
          for(int i=0;i<r;i++){
              cnt+=countSmaller(matrix[i],mid);
          }
          if(cnt<=(r*c)/2) low = mid+1;
          else high = mid-1;
      }
      return low;
  }

//Find the element that appears once in sorted array, and rest element appears twice 

/*You need to find the left half---where first instance is at even index and second instance is at odd index*/


int singleNonDuplicate(vector<int>& nums) {
  int n = nums.size();
  int low = 0, high = n-2;
  while(low<=high){
      int mid = (low+high)/2;
      if(mid%2==0){
          if(nums[mid+1]==nums[mid]) low = mid+1;
          else high = mid-1;
      }else{
          if(nums[mid-1]==nums[mid]) low = mid+1;
          else high = mid-1;
      }
  }
  return nums[low];
}


//Median of two sorted arrays
//striver:  https://www.youtube.com/watch?v=NTop3VTjmxk&list=PLgUwDviBIf0p4ozDR_kJJkONnb1wdx2Ma&index=66


double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
  if(nums2.size() < nums1.size()) return findMedianSortedArrays(nums2, nums1);
  int n1 = nums1.size();
  int n2 = nums2.size(); 
  int low = 0, high = n1;

  while(low <= high) {
      int cut1 = (low+high) >> 1;
      int cut2 = (n1 + n2 + 1) / 2 - cut1; 


      int left1 = cut1 == 0 ? INT_MIN : nums1[cut1-1];
      int left2 = cut2 == 0 ? INT_MIN : nums2[cut2-1]; 

      int right1 = cut1 == n1 ? INT_MAX : nums1[cut1];
      int right2 = cut2 == n2 ? INT_MAX : nums2[cut2]; 


      if(left1 <= right2 && left2 <= right1) {
          if( (n1 + n2) % 2 == 0 ) 
              return (max(left1, left2) + min(right1, right2)) / 2.0; 
          else 
              return max(left1, left2); 
      }
      else if(left1 > right2) {
          high = cut1 - 1; 
      }
      else {
          low = cut1 + 1; 
      }
  }
  return 0.0; 
}
