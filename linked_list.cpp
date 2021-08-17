
/*Factorial of large number using ll*/

#include <iostream>
using namespace std;

class node{
    public:
        int data;
        //making prev pointer bcz we multiply frm right to left
        node *prev;
        node(int val){
            data=val;
            prev=NULL;
        }
};

//recursive display

void display(node* tail){
    if(tail==NULL) return;
    display(tail->prev);
    cout<<tail->data;
}

void multiply(node* tail, int x){
    node *temp = tail, *PrevNode = tail;
    int carry = 0;
    while(temp){
        int val = temp->data * x + carry;
        temp->data = val%10;
        carry = val/10;
        PrevNode = temp;
        temp = temp->prev;
    }
    while(carry){
        PrevNode->prev = new node(carry%10);
        carry/=10;
        PrevNode = PrevNode->prev;
    }
}

int main(){
    node *tail = new node(1);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        multiply(tail,i);
    }
    display(tail);
    return 0;
}



// #include <iostream>
// using namespace std;

// class node{
//     public:
//         int data;
//         node *next;
//         node(int val){
//             data=val;
//             next=NULL;
//         }
// };

// void insert_at_tail(node* &head,int val){
//     node* n=new node(val);
//     if(head==NULL){
//         head=n;
//         return;
//     }
//     node* temp=head;
//     while (temp->next!=NULL)
//     {
//         temp=temp->next;
//     }
//     temp->next=n;
    
// }

// void insert_at_head(node *&head,int val){
//     node* n=new node(val);
//     n->next=head;
//     head=n;
// }

// void display_ll(node* head){
//     node* temp=head;
//     while(temp!=NULL){
//         cout<<temp->data<<" -> ";
//         temp=temp->next;
//     }
//     cout<<"NULL"<<endl;
// }

// // // Linear Search
// bool search(node* head,int key){
//     node* temp=head;
//     while(temp!=NULL){
//         if(temp->data==key){
//             return true;
//         }
//         temp=temp->next;
//     }
//     return false;
// }

// void delete_at_head(node* &head){
//     node* todelete=head;
//     head=head->next;
//     delete todelete;
// }

// // //deletion
// void deletion(node* &head,int val){
//     if(head==NULL){
//         return;
//     }
//     if(head->next==NULL){
//         delete_at_head(head);
//         return;
//     }
//     node* temp=head;
//     while(temp->next->data!=val){
//         temp=temp->next;
//     }
//     node* todelete=temp->next;
//     temp->next=temp->next->next;
//     delete todelete;
// }

// node* reverse_iteratively(node* &head){
//     node* prevptr=NULL;
//     node* currptr=head;
//     node* nextptr;
//     while(currptr!=NULL){
//         nextptr=currptr->next;
//         currptr->next=prevptr;

//         prevptr=currptr;
//         currptr=nextptr;
//     }
//     return prevptr;
// }

// node* reverse_rec(node* &head){

//     if (head==NULL || head->next==NULL)
//     {
//         return head;
//     }
    
//     node* newhead=reverse_rec(head->next);
//     head->next->next=head;
//     head->next=NULL;
//     return newhead;
// }

// node* reversek(node* &head,int k){
//     node* prev=NULL;
//     node* curr=head;
//     node* nextptr;
//     int count=0;
//     while(curr!=NULL && count<k){
//         nextptr=curr->next;
//         curr->next=prev;
//         prev=curr;
//         curr=nextptr;
//         count++;
//     }
//     if(nextptr!=NULL){
//         head->next=reversek(nextptr,k);
//     }
//     return prev;
// }

// int find_middle(node* head){
//     node* slow=head;
//     node* fast=head;
//     if(head->next==NULL){
//         return head->data;
//     }
//     while(fast->next!=NULL){
//         slow=slow->next;
//         fast=fast->next->next;
//     }
//     return slow->data;
// }

// int main(){
    
//     node* head=NULL;
//     insert_at_tail(head,1);
//     insert_at_tail(head,2);
//     insert_at_tail(head,3);
//     insert_at_tail(head,4);
//     insert_at_tail(head,5);
//     insert_at_head(head,6);
//     insert_at_head(head,7);
//     // cout<<"Before deletion"<<endl;
//     // display_ll(head);
//     // // cout<<search(head,8)<<endl;
//     // // cout<<search(head,2)<<endl;
//     // deletion(head,3);
//     // cout<<"After deleting element 3"<<endl;
//     // display_ll(head);
//     // delete_at_head(head);
//     // cout<<"After deleting head"<<endl;
//     // display_ll(head);
//     // cout<<"Actual LL: "<<endl;
//     // display_ll(head);
//     // cout<<"After reversing: "<<endl;
//     // node* newhead=reverse_rec(head);
//     // display_ll(newhead);
//     // cout<<"Actual LL: "<<endl;
//     // display_ll(head);
//     // cout<<"After reversing: "<<endl;
//     // node* newhead=reverse_iteratively(head);
//     // display_ll(newhead);
//     // display_ll(head);
//     // node* newhead=reversek(head,2);
//     // display_ll(newhead);
//     // cout<<find_middle(head)<<endl;
// return 0;
// }
