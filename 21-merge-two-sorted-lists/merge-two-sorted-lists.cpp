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
    ListNode* mergeTwoLists(ListNode* a, ListNode* b) {

        // ListNode* tempA = a;
        // ListNode* tempB = b;

        // ListNode* c = new ListNode(100); // dummy node
        // ListNode* tempC = c;

        // while(tempA != NULL && tempB != NULL){

        //     if(tempA->val <= tempB->val){

        //         ListNode* t = new ListNode(tempA->val);
        //         tempC->next = t;
        //         tempC = t;

        //         tempA = tempA->next;
        //     }
        //     else{

        //         ListNode* t = new ListNode(tempB->val);
        //         tempC->next = t;
        //         tempC = t;

        //         tempB = tempB->next;
        //     }
        // }

        // if(tempA == NULL){
        //     tempC->next = tempB;
        // }
        // else{
        //     tempC->next = tempA;
        // }

        // return c->next;

        // space complexity o(1)
        ListNode* c = new ListNode(100);
        ListNode* tempc = c;
        while(a != NULL && b != NULL){
            if(a->val<=b->val){
                tempc->next = a;
                a = a->next;
                tempc = tempc->next;
            }
            else{
                  tempc->next = b;
                b = b->next;
                tempc = tempc->next;
            }
        }
        if(a == NULL){
            tempc->next = b;
        }
        else{
            tempc->next = a;
        }
        return c->next;
    }
};