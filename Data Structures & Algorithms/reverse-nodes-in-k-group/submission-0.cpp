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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode dummyNode;
        ListNode* nodeBeforeK = &dummyNode;

        dummyNode.next = head;
        ListNode* curr = nodeBeforeK->next;

        int count = 1;

        while (curr) {
            if (count == k) {
                ListNode* temp = curr->next;
                ListNode* tailReversed = nodeBeforeK->next;

                ListNode* headReversed = ReverseListK(nodeBeforeK->next, k);
                nodeBeforeK->next = headReversed;
                tailReversed->next = temp;
                nodeBeforeK = tailReversed;

                curr = tailReversed;
                count = 0;
            }
            curr = curr->next;
            count++;
        }

        return dummyNode.next;
    }
    ListNode* ReverseListK(ListNode* node, int lenght) {
        ListNode* curr = node;
        ListNode* prev = nullptr;

        int counter = 0;

        while (counter < lenght) {
            ListNode* temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
            counter++;
        }
        return prev;
    }
};














