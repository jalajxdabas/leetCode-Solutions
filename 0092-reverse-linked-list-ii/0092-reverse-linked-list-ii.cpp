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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(head == NULL || head->next == NULL || left == right) return head;
        ListNode* lnode = head;
        ListNode* rnode = head;

            ListNode* prev= NULL;
            ListNode* next = NULL;

            for(int i=1; i<left; i++){
                prev = lnode;
                lnode = lnode->next;
            }

            for(int i=1; i<right; i++){
                rnode = rnode->next;
            }
            if(rnode) next = rnode->next;


        ListNode* p = next;
        ListNode* curr = lnode;
        ListNode* n = NULL;

        while(curr != rnode){
            n = curr->next;
            curr->next = p;
            p = curr;
            curr = n;
        }
        curr->next = p;
        if(prev) prev->next = curr;
        else head = curr;
        return head;

    }
};