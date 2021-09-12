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
