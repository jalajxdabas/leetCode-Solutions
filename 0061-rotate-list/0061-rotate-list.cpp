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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL || head->next == NULL || k == 0) return head;
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = NULL;
        ListNode* prev2 = NULL;

        int length = 0;
        while(fast){
            length++;
            fast = fast->next;
        }

        k = k%length;
        if(k==0) return head;
        fast = head;
        for(int i=0; i<k; i++){
            fast = fast->next;
        }

        while(fast!=NULL){
            prev2 = fast;
            fast = fast->next;
            prev = slow;
            slow = slow->next;
        }

        prev2->next = head;
        prev->next = NULL;

        return slow;
    }
};