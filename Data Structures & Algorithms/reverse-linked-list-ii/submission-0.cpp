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
    ListNode* reverse_linked_list(ListNode* head){
        ListNode* prev = nullptr;
        while(head){
            ListNode* remain = head->next;
            head->next = prev;
            prev = head;
            head = remain;
        }
        return prev;
        
    }

    ListNode* reverseBetween(ListNode* head, int left, int right) {
       ListNode* dummy = new ListNode(0);
       dummy->next = head;

       ListNode* a = dummy;
       for(int i = 1; i<left; i++) a = a->next;
       ListNode* b = a->next;
       ListNode* c = b;
       for(int i = 0; i<(right - left); i++) c = c->next;
       ListNode* d = c->next;

       c->next = nullptr;
       a->next = reverse_linked_list(b);
       b->next = d;

       return dummy->next;
    }
};