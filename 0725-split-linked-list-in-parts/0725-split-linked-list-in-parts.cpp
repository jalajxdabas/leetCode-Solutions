class Solution {
public:
    int getLength(ListNode* head){
        int len = 0;
        while(head != NULL){
            len++;
            head = head->next;
        }
        return len;
    }

    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int len = getLength(head);
        int baseSize = len / k;
        int extra = len % k;

        vector<ListNode*> ans;

        ListNode* curr = head;

        for(int i = 0; i < k; i++){
            ListNode* partHead = curr;
            int partSize = baseSize + (extra > 0 ? 1 : 0);

            for(int j = 0; j < partSize - 1 && curr != NULL; j++){
                curr = curr->next;
            }

            if(curr != NULL){
                ListNode* nextPart = curr->next;
                curr->next = NULL;
                curr = nextPart;
            }

            ans.push_back(partHead);
            if(extra > 0) extra--;
        }

        return ans;
    }
};
