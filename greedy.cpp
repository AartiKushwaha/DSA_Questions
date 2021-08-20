#include <bits/stdc++.h>
using namespace std;

struct meeting {
    int start;
    int end;
    int pos; 
}; 
bool comparator(struct meeting m1, meeting m2) 
{ 
    if (m1.end < m2.end) return true; 
    else if(m1.end > m2.end) return false; 
    else if(m1.pos < m2.pos) return true; 
    return false; 
} 
void maxMeetings(int s[], int e[], int n) {
    struct meeting meet[n]; 
    for(int i = 0;i<n;i++) {
        meet[i].start = s[i], meet[i].end = e[i], meet[i].pos = i+1; 
    }
    
    sort(meet, meet+n, comparator); 
    
    vector<int> answer;
    
    int limit = meet[0].end; 
    answer.push_back(meet[0].pos); 
    
    for(int i = 1;i<n;i++) {
        if(meet[i].start > limit) {
            limit = meet[i].end; 
            answer.push_back(meet[i].pos); 
        }
    }
    for(int i = 0;i<answer.size();i++) {
        cout << answer[i] << " "; 
    }
    
}

int main(){
    int n;
    cin>>n;
    int start[n],end[n];
    for(int i=0;i<n;i++){
        cin>>start[i];
    }
    for(int i=0;i<n;i++){
        cin>>end[i];
    }
    maxMeetings(start, end, n);
    return 0;
}



//Minimum no of platforms

// Sort arrival and departure arrays
sort(arr, arr + n);
sort(dep, dep + n);

// plat_needed indicates number of platforms
// needed at a time
int plat_needed = 1, result = 1;
int i = 1, j = 0;

// Similar to merge in merge sort to process
// all events in sorted order
while (i < n && j < n) {
    // If next event in sorted order is arrival,
    // increment count of platforms needed
    if (arr[i] <= dep[j]) {
        plat_needed++;
        i++;
    }

    // Else decrement count of platforms needed
    else if (arr[i] > dep[j]) {
        plat_needed--;
        j++;
    }

    // Update result if needed
    if (plat_needed > result)
        result = plat_needed;
}

return result;
