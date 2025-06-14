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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;
        ListNode* slow = head;
        ListNode* fast = head->next;

        while(fast!=NULL){
            if(slow->val == fast->val) fast = fast->next;
            else{
                slow->next = fast;
                slow = fast;
            }
        }
        slow->next = NULL;
        return head;
    }
};