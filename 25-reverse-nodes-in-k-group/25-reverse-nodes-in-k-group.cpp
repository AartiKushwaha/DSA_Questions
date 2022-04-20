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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* nxt;
        ListNode* temp = head;
        int cnt=0;
        for(int i=0; i<k; i++){
            if(temp==NULL) return head;
            temp = temp->next;
        }
        while(curr and cnt<k){
            nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
            cnt++;
        }
        if(nxt) head->next = reverseKGroup(nxt, k);
        return prev;
    }
};