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

    // function to find kth node
    ListNode* getKthNode(ListNode* curr, int k) {

        while(curr && k > 0) {
            curr = curr->next;
            k--;
        }

        return curr;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {

        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        ListNode* prevGroup = dummy;

        while(true) {

            // find kth node
            ListNode* kth = getKthNode(prevGroup, k);

            // if less than k nodes remain
            if(kth == NULL)
                break;

            ListNode* groupNext = kth->next;

            // reverse current group
            ListNode* prev = groupNext;
            ListNode* curr = prevGroup->next;

            while(curr != groupNext) {

                ListNode* temp = curr->next;

                curr->next = prev;

                prev = curr;

                curr = temp;
            }

            // reconnect
            ListNode* temp = prevGroup->next;

            prevGroup->next = kth;

            prevGroup = temp;
        }

        return dummy->next;
    }
};