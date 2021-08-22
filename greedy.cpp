// #include <bits/stdc++.h>
// using namespace std;

// struct meeting {
//     int start;
//     int end;
//     int pos; 
// }; 
// bool comparator(struct meeting m1, meeting m2) 
// { 
//     if (m1.end < m2.end) return true; 
//     else if(m1.end > m2.end) return false; 
//     else if(m1.pos < m2.pos) return true; 
//     return false; 
// } 
// void maxMeetings(int s[], int e[], int n) {
//     struct meeting meet[n]; 
//     for(int i = 0;i<n;i++) {
//         meet[i].start = s[i], meet[i].end = e[i], meet[i].pos = i+1; 
//     }
    
//     sort(meet, meet+n, comparator); 
    
//     vector<int> answer;
    
//     int limit = meet[0].end; 
//     answer.push_back(meet[0].pos); 
    
//     for(int i = 1;i<n;i++) {
//         if(meet[i].start > limit) {
//             limit = meet[i].end; 
//             answer.push_back(meet[i].pos); 
//         }
//     }
//     for(int i = 0;i<answer.size();i++) {
//         cout << answer[i] << " "; 
//     }
    
// }

// int main(){
//     int n;
//     cin>>n;
//     int start[n],end[n];
//     for(int i=0;i<n;i++){
//         cin>>start[i];
//     }
//     for(int i=0;i<n;i++){
//         cin>>end[i];
//     }
//     maxMeetings(start, end, n);
//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;

// struct Job{
//     int id;
//     int dead;
//     int profit;
// };

// bool comp(Job j1, Job j2){
//     return (j1.profit > j2.profit);
// }

// vector<int> JobScheduling(Job arr[], int n) 
// { 
//     vector<int> ans;
//     sort(arr, arr+n ,comp);
//     int cnt = 0, maxPro = 0;
//     int maxDead = arr[0].dead;
//     for(int i=1; i<n; i++){
//         maxDead = max(maxDead, arr[i].dead);
//     }
//     int freq[maxDead];
//     for(int i=0;i<maxDead;i++){
//         freq[i] = -1;
//     }
//     for(int i = 0; i < n; i++){
//         for(int j = arr[i].dead-1; j >=0; j--){
//             if(freq[j]==-1){
//                 freq[j] = arr[i].id;
//                 cnt++;
//                 maxPro += arr[i].profit;
//                 break;
//             }
//         }
//     }
//     ans.push_back(cnt);
//     ans.push_back(maxPro);
//     return ans;
// } 

// int main(){
//     struct Job arr[4];
//     cout<<"Input"<<endl;
//     for(int i=0; i<4; i++){
//         cin>>arr[i].id>>arr[i].dead>>arr[i].profit;
//     }
//     vector<int> ans;
//     ans = JobScheduling(arr, 4);
//     for(auto it: ans){
//         cout<<it<<" ";
//     }
//     return 0;
// }

// Fractional Knapsack


// #include <bits/stdc++.h>
// using namespace std;
// struct knap{
//     int value;
//     int weight;
// };
// bool comp(knap k1, knap k2){
//     if((double)k1.value/(double)k1.weight > (double)k2.value/(double)k2.weight) return true;
//     else if((double)k1.value/(double)k1.weight < (double)k2.value/(double)k2.weight) return false;
//     else return (k1.value > k2.value);
//     return false;
// }
// double maxValue(knap arr[], int wt, int n){
//     sort(arr, arr+n, comp);
//     double ans = arr[0].value;
//     int currWt = arr[0].weight;
//     for(int i=1;i<n;i++){
//         int w = currWt+arr[i].weight;
//         if(currWt>=wt) break;
//         if(w<=wt){
//             ans+=arr[i].value;
//             currWt+=arr[i].weight;
//         }else{
//             int rw = wt-currWt;
//             double wbv = (double)arr[i].value/(double)arr[i].weight;
//             ans+=wbv*rw;
//             currWt+=rw;
//         }
//     }
//     return ans;
// }

// int main(){
//     cout<<"Enter n: "<<endl;
//     int n;
//     cin>>n;
//     struct knap arr[n];
//     for(int i=0;i<n;i++){
//         cin>>arr[i].value>>arr[i].weight;
//     }
//     int wt;
//     cout<<"Enter weight: "<<endl;
//     cin>>wt;
//     double ans = maxValue(arr, wt, n);
//     cout<<ans<<endl;
//     return 0;
// }


//Split a string in balanced strings

// #include <bits/stdc++.h>
// using namespace std;

// int splitStr(string s){
//     int n = s.size();
//     int r = 0, l = 0, i = 0, ans = 0;
//     while(i < n){
//         if(s[i] == 'R') r++;
//         else if(s[i] == 'L') l++;
//         if(r == l){
//             ans++;
//             l=0;r=0;
//         }
//         i++;
//     }
//     return ans;
// }

// int main(){
//     string st;
//     cin>>st;
//     int ans = splitStr(st);
//     cout<<ans<<endl;
//     return 0;
// }

//strictly increasing array

// #include <bits/stdc++.h>
// using namespace std;

// int minOperations(int arr[], int n){
//     int ans = 0;
//     for(int i=0; i<n-1; i++){
//         if(arr[i+1]<=arr[i]){
//             int diff = (arr[i]+1)-arr[i+1];
//             ans+=diff;
//             arr[i+1] = arr[i]+1;
//         }
//     }
//     return ans;
// }
// int main(){
//     int n;
//     cin>>n;
//     int arr[n];
//     for(int i=0;i<n;i++){
//         cin>>arr[i];
//     }
//     int ans = minOperations(arr, n);
//     cout<<ans<<endl;
//     return 0;
// }   

//Truck leetcode


bool static comp(vector<int> &a, vector<int> &b){
    return (a[1] > b[1]);
}

int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
    int n = boxTypes.size();
    sort(boxTypes.begin(),boxTypes.end(), comp);
    int ans=0;
    
    for(int i=0;i<boxTypes.size();i++){
        int box_count=min(boxTypes[i][0],truckSize);
        ans+=box_count*boxTypes[i][1];
        truckSize-=box_count;
        if(truckSize==0)
            break;
    }
    return ans;
}


