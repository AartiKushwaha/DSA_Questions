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

void buildTree(int arr[], int tree[], int st, int end, int curIdx){
    //base case
    if(st==end){
        tree[curIdx] = arr[st];
        return;
    }
    //recursive case POSTORDER BUILD
    int mid = (st+end)/2;
    buildTree(arr, tree, st, mid, 2*curIdx+1);
    buildTree(arr, tree, mid+1, end, 2*curIdx+2);
    tree[curIdx] = min(tree[2*curIdx+1], tree[2*curIdx + 2]);
    return;
}

int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++) cin>>arr[i];
    int tree[4*n+1];               //max size of the array conatining tree
    buildTree(arr, tree, 0, n-1, 1);
    for(int i=0; i<4*n + 1; i++) cout<<tree[i]<<" ";
    cout<<endl;
    return 0;
}
