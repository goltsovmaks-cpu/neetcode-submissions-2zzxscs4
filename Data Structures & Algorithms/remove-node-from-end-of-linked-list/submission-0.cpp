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
        int lenght = 0;
        ListNode* curr = head;
        while (nullptr != curr) {
            lenght++;
            curr = curr->next;
        }
        int idxBeforeRemove = lenght - n;

        ListNode dummyHead;
        dummyHead.next = head;
        curr = &dummyHead;

        for (int i = 0; i < idxBeforeRemove; i++) {
            curr = curr->next;
        }
        ListNode* toRemove = curr->next;
        curr->next = curr->next->next;
        delete toRemove;
        
        return dummyHead.next;
    }
};










