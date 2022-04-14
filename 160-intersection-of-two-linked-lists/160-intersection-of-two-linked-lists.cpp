/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *h1, ListNode *h2) {
        if(h1==NULL or h2==NULL) return NULL;
        ListNode* d1 = h1;
        ListNode* d2 = h2;
        while(d1!=d2){
            while(d1 and d2){
                if(d1==d2) return d1;
                d1 = d1->next;
                d2 = d2->next;
            }
            if(d1!=d2){
                if(!d1) d1 = h2;
                if(!d2) d2 = h1;   
            }
        }
        return d1;
    }
};