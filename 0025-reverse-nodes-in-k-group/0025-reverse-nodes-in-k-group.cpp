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
    int getLength(ListNode* head){
        if(head == NULL) return 0;
        ListNode* temp = head;

        int len = 0;
        while(temp){
            len++;
            temp = temp->next;
        }
        return len;
    }


    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head == NULL || head->next == NULL) return head;

        int len = getLength(head);
        if(len < k) return head;

        int count = 0;
        ListNode* curr = head;
        ListNode* prev = NULL;
        ListNode* next = NULL;

        while(curr != NULL && count < k){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            count++;
        }
         
        if(next!=NULL) head->next = reverseKGroup(next, k);

        return prev;
    }
};