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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* ans = new ListNode(0);
        ListNode* h1 = l1;
        ListNode* h2 = l2;
        ListNode* curr = ans;
        int carry = 0;
        while(h1 || h2){
            int x1 = (h1)?(h1->val):0;
            int x2 = (h2)?(h2->val):0;
            int sum = x1+x2+carry;
            carry = sum/10;
            curr->next = new ListNode(sum%10);
            curr = curr->next;
            if(h1) h1 = h1->next;
            if(h2) h2 = h2->next;
        }
        if(carry) curr->next = new ListNode(carry);
        return ans->next;
    }
};