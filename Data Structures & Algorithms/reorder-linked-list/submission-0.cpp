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
    void reorderList(ListNode* head) {
        if(!head) return;
        if(!head->next) return;
        if(!head->next->next) return;



        ListNode* x = head;
        while(x){

            ListNode* prev = nullptr;
            ListNode* curr = x->next;
            ListNode* remain = x->next->next;
            
            while(curr){
                curr->next = prev;
                prev = curr;
                curr = remain;
                if(remain){
                    remain = remain->next;
                }
            }

            x->next = prev;
            x = x->next;
        }

        

        
        
    }
};
