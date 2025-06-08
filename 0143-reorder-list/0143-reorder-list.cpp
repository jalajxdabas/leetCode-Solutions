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

        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }

    ListNode* reverseList(ListNode* head){
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* next = NULL;

        while(curr){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
    void reorderList(ListNode* head) {
        if(head == NULL || head->next == NULL) return;
        ListNode* middle = getMiddle(head);

        ListNode* right = middle->next;
        ListNode* rev = reverseList(right);
        
        ListNode* temp1 = head;
        ListNode* temp2 = rev;

        ListNode* ans = new ListNode(0);
        ListNode* ansHead = ans;

        while(temp1 && temp2){
            ans->next = temp1;
            temp1 = temp1->next;
            ans = ans->next;

            ans->next = temp2;
            temp2 = temp2->next;
            ans = ans->next;
        }

        while(temp1 != right){
            ans->next = temp1;
            temp1 = temp1->next;
            ans = ans->next;
        }

        ans->next = NULL;

        head = ansHead->next;
        return;
    }
};