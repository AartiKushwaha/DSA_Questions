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
        ListNode* temp = head;
        int cnt=0;
        while(temp->next){
            temp = temp->next;
            cnt++;
        }
        cnt++;
        ListNode* st = head;
        ListNode* en = head;
        for(int i=0; i<k-1; i++){
            st = st->next;
        }
        for(int i=0; i<(cnt-k); i++){
            en = en->next;
        }
        int t = st->val;
        st->val = en->val;
        en->val = t;
        return head;
    }
};