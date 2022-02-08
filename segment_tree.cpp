//BUILDING A SEGMENT TREE

/*If n is a power of 2, then there are no dummy nodes. 
So the size of the segment tree is 2n-1 (n leaf nodes and n-1 internal nodes). 
If n is not a power of 2, then the size of the tree will be 2*x – 1 where x is the smallest 
power of 2 greater than n. For example, when n = 10, then size of array representing segment tree is 2*16-1 = 31. 
An alternate explanation for size is based on heignt. Height of the segment tree will be ⌈log₂n⌉. 
Since the tree is represented using array and relation between parent and child indexes must be maintained, 
size of memory allocated for segment tree will be 2 * 2⌈log2n⌉  – 1.
*/

#include<bits/stdc++.h>
using namespace std;
int arr[50], tree[50];
void buildTree(int st, int end, int curIdx){
    //base case
    if(st==end){
        tree[curIdx] = arr[st];
        return;
    }
    //recursive case POSTORDER BUILD
    int mid = (st+end)/2;
    buildTree(st, mid, 2*curIdx+1);
    buildTree( mid+1, end, 2*curIdx+2);
    tree[curIdx] = max(tree[2*curIdx+1], tree[2*curIdx+2]);
    return;
}

int min_query(int st, int end, int qs, int qe, int idx){
    //Complete overlap
    if(st>=qs and end<=qe) return tree[idx];
    //No Overlap
    if(end<qe || st>qs) return INT_MIN;
    //Partial overlap
    int mid = (st+end)/2;
    int left = min_query(st, mid, qs, qe, 2*idx+1);
    int right = min_query(mid+1, end, qs, qe, 2*idx+2);
    return max(left, right);
}

int main()
{
    int n,q;
    cin>>n;
    for(int i=0; i<n; i++) cin>>arr[i];              //max size of the array conatining tree
    buildTree(0, n-1, 0);
    cin>>q;
    while(q--){
        int qs,qe;
        cin>>qs>>qe;
        int ans = min_query(0, n-1, qs, qe, 0);
        cout<<ans<<endl;
    }
    return 0;
}

