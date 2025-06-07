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
    void insertAtTail(ListNode* &temp, ListNode* &head, ListNode* &tail){
        tail->next = temp;
        tail = temp;
    }
    ListNode* getMiddle(ListNode* &head){
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast!=NULL){
            fast=fast->next;
            if(fast!=NULL && fast->next!=NULL){
                fast=fast->next;
                slow=slow->next;
            }
        }
        return slow;
    }
    ListNode* merge(ListNode* list1, ListNode* list2){
        ListNode* newNode = new ListNode(-1);
        ListNode* head = newNode;
        ListNode* tail = newNode;

        while(list1 != NULL && list2 != NULL){
            if(list1-> val <= list2-> val){
                ListNode* temp = list1;
                list1 = list1->next;
                temp->next = NULL;
                insertAtTail(temp, head, tail);
            }
            else{
                ListNode* temp = list2;
                list2 = list2->next;
                temp->next = NULL;
                insertAtTail(temp, head, tail);
            }
        }
        while(list1!=NULL){
                ListNode* temp=list1;
                    list1=list1->next;
                    temp->next=NULL;
                insertAtTail(temp,head,tail);
            }

        while(list2!=NULL){
                ListNode* temp=list2;
                    list2=list2->next;
                    temp->next=NULL;
                insertAtTail(temp,head,tail);
        }

        ListNode* temp=head->next;
        delete newNode;
        return temp;


    }
    ListNode* sortList(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;

        ListNode* middle = getMiddle(head);
        ListNode* right = middle->next;
        middle->next = NULL;
        ListNode* left = head;

        left = sortList(left);
        right = sortList(right);
        return merge(left, right);
    }
};