//https://leetcode.com/problems/min-cost-climbing-stairs/

int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        int dp[n+1];
        dp[n] = 0;
        for(int i=n-1; i>=0; i--){
            int mi = INT_MAX;
            for(int j=1;j<=2 and (i+j)<=n;j++){
                mi = min(mi, dp[i+j]);
            }
            dp[i] = mi+cost[i];
        }
        if(dp[0]<dp[1]) return dp[0];
        else return dp[1];
    }
//https://practice.geeksforgeeks.org/problems/gold-mine-problem2608/1

int maxGold(int n, int m, vector<vector<int>> arr)
    {
        int dp[n][m];
        for(int j=m-1;j>=0;j--){
            for(int i=0;i<n;i++){
                int mx = INT_MIN;
                if(j==m-1) dp[i][j] = arr[i][j];
                else if(i==0 and n==1){
                    dp[i][j] = dp[i][j+1]+arr[i][j];
                }
                else if(i==0 and n>1){
                    mx = max(dp[i][j+1], dp[i+1][j+1]);
                    dp[i][j] = mx+arr[i][j];
                }else if(i==n-1){
                    mx = max(dp[i][j+1], dp[i-1][j+1]);
                    dp[i][j] = mx+arr[i][j];
                }else{
                    mx = max(dp[i][j+1], max(dp[i-1][j+1], dp[i+1][j+1]));
                    dp[i][j] = mx+arr[i][j];
                }
            }
        }
        int ans = 0;
        for(int i=0;i<n;i++){
            ans = max(ans, dp[i][0]);
        }
        return ans;
    }

//https://practice.geeksforgeeks.org/problems/subset-sum-problem-1611555638/1/?category[]=Dynamic%20Programming&category[]=Dynamic%20Programming&page=4&query=category[]Dynamic%20Programmingpage4category[]Dynamic%20Programming

bool isSubsetSum(int n, int arr[], int sum){
        // code here 
        int dp[n+1][sum+1];
        for(int i=0;i<n+1;i++){
            dp[i][0] = 1;
        }
        for(int j=1;j<sum+1;j++){
            dp[0][j] = 0;
        }
        for(int i=0;i<n+1;i++){
            for(int j=0;j<sum+1;j++){
                if(i==0 or j==0) continue;
                else{
                    bool wo = dp[i-1][j];
                    bool w = dp[i-1][j-arr[i-1]];
                    dp[i][j] = wo || w;
                }
            }
        }
        return dp[n][sum];
    }

//https://leetcode.com/problems/coin-change-2/

int change(int amount, vector<int>& coins) {
        int n = amount+1;
        int dp[n];
        for(int i=0;i<n;i++){
            dp[i]=0;
        }
        dp[0] = 1;
        int j=0;
        while(j<coins.size()){
            for(int i=coins[j];i<n;i++){
                if(i-coins[j] >=0){
                    dp[i]+=dp[i-coins[j]];
                }
            }
            j++;
        }
        
        return dp[n-1];
    }


//https://practice.geeksforgeeks.org/problems/0-1-knapsack-problem0945/1#

int knapSack(int W, int wt[], int val[], int n) 
    { 
       // Your code here
       int dp[n+1][W+1];
       for(int i=0;i<n+1;i++){
           for(int j=0;j<W+1;j++){
               if(i==0 or j==0) dp[i][j] = 0;
           }
       }
       for(int i=1;i<n+1;i++){
           for(int j=1;j<W+1;j++){
               if(j<wt[i-1]){
                   dp[i][j] = dp[i-1][j];
               }else{
                   int ex = dp[i-1][j];
                   int in = val[i-1]+dp[i-1][j-wt[i-1]];
                   dp[i][j] = max(ex, in);
               }
           }
       }
       return dp[n][W];
    }
