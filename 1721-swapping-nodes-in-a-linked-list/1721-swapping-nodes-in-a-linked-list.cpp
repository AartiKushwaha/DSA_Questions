/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* p1 = head, *p2 = head, *temp = NULL;
        for(int i=0; i<(k-1); i++){
            p1 = p1->next;
        }
        temp = p1;
        p1 = p1->next;
        while(p1){
            p1 = p1->next;
            p2 = p2->next;
        }
        swap(p2->val, temp->val);
        return head;
    }
};