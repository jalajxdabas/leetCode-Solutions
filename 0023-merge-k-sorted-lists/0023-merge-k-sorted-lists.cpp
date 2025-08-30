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

class compare{
    public: 
    bool operator() (ListNode* a, ListNode* b){
        return a->val > b->val;
    }
};
class Solution {
public:
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int k = lists.size();
        if(k == 0) return NULL;

        priority_queue<ListNode*, vector<ListNode*>, compare> mini;

        for(int i=0; i<k; i++){
            if(lists[i] != NULL) mini.push(lists[i]);
        }

        ListNode* head = NULL;
        ListNode* tail = NULL;

        while(!mini.empty()){
            ListNode* top = mini.top();
            mini.pop();

            if(top->next) mini.push(top->next);

            if(head == NULL){
                head = top;
                tail = top;
            }
            else{
                tail->next = top;
                tail = top;
            }
        }

        return head;
    }
};