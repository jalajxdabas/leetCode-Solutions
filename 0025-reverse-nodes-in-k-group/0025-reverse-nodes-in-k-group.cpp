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
        int count = 0;
        ListNode* temp = head;
        while(temp){
            temp = temp->next;
            count++;
        }
        return count;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head == NULL || head->next == NULL) return head;


        int length = getLength(head);
        if(length < k) return head;

        ListNode* prev = NULL;
        ListNode* next = NULL;
        ListNode* curr = head;
        int count = 0;

        while(curr != NULL && count<k){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            count++;
        }

        if(next!=NULL){
            head->next = reverseKGroup(next, k);
        }
        return prev;
    }
};