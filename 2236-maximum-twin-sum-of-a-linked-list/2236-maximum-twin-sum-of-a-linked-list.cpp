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
    ListNode* getMiddle(ListNode* head){
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast != NULL && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    ListNode* reverse(ListNode* head){
        if(head == NULL || head->next == NULL) return head;

        ListNode* curr = head;
        ListNode* prev = NULL;
        ListNode* next = NULL;

        while(curr){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
    int pairSum(ListNode* head) {
        ListNode* middle = getMiddle(head);
        ListNode* temp1 = reverse(middle);
        ListNode* temp2 = head;
        int ans = 0;

        while(temp1 != NULL){
            ans = max(ans, temp1->val + temp2->val);
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        return ans;

    }
};