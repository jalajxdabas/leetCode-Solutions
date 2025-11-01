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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int> st(nums.begin(), nums.end());

        ListNode* dummy = new ListNode(-1); 
        ListNode* tail = dummy;

        while(head){
            if(st.find(head->val) == st.end()){
                tail->next = new ListNode(head->val);
                tail = tail->next;
            }
            head = head->next;
        }
        return dummy->next;


    }
};