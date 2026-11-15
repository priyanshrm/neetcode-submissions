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
    void reverse_linked_list(ListNode*& head){
        ListNode* prev = nullptr;
        ListNode* curr = head;
        ListNode* remain = head->next;

        while(curr){
            curr->next = prev;
            prev = curr;
            curr = remain;
            if(remain){
                remain = remain->next;
            }
        }
        head = prev;
    }

    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(!head) return nullptr;
        reverse_linked_list(head);
        ListNode* x = head;
        ListNode* y = nullptr;
        while(--n){
            y = x;
            x = x->next;
        }
        if(y){
            y->next = x->next;
        } else {
            head = x->next;
        }

        delete x;
        reverse_linked_list(head);

        return head;
    }
};
