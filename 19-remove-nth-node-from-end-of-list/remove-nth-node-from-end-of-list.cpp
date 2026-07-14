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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
         // for single list
        if(head->next == NULL) return NULL;
        int size = 0;
        ListNode* temp = head;
        // count size
        while(temp != NULL){
            size++;
            temp = temp->next;
        }
         // delete head case
        if(n == size){
            return head->next;
        }

        // node before target
        int idx = size - n;
        // reset temp
        temp = head;
        // treverse temp to delete node
        for(int i = 0;i<idx-1;i++){
            temp = temp->next;
        }
        
        temp->next  = temp->next->next;
        return head;
    }
};