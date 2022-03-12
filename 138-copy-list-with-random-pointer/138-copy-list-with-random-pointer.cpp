/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* first = head;
        Node* second = head;
        while(first!=NULL){
            second = first->next;
            
            Node* copy = new Node(first->val);
            first->next = copy;
            copy->next = second;
            first = second;
        }
        first = head;
        while(first!=NULL){
            if(first->random!=NULL){
                first->next->random  = first->random->next;
            }
            first = first->next->next;
        }
        first = head;
        Node* dummy = new Node(0);
        Node* copy = dummy;
        while(first!=NULL){
            second = first->next->next;
            copy->next = first->next;
            first->next = second;
            copy = copy->next;
            first = first->next;
        }
        return dummy->next;
    }
};