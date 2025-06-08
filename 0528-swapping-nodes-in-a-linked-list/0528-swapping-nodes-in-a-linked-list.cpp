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
    ListNode* swapNodes(ListNode* head, int k) {
        if (!head || !head->next) return head;
        int length = 0;
        ListNode* temp = head;
        while (temp) {
            length++;
            temp = temp->next;
        }

        if (k > length) return head;

        ListNode* kStart = head;
        for (int i = 1; i < k; i++)
            kStart = kStart->next;

        ListNode* kEnd = head;
        for (int i = 1; i <= length - k; i++)
            kEnd = kEnd->next;

        swap(kStart->val, kEnd->val);

        return head;
    }
};