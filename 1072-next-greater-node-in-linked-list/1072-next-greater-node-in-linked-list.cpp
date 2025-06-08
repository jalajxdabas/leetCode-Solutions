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
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int>k;
        while (head!=NULL){
            ListNode* tra=head;
            int x=-1;
            while (tra->next!=NULL){
                tra=tra->next;
                if (tra->val>head->val){x=tra->val;break;}
            }
            if (x==-1){k.push_back(0);}
            else {k.push_back(x);}
            head=head->next;
        }
        return k;
    }
};