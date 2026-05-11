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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode dummyNode;
        dummyNode.next = head;
        ListNode* beforeNode = &dummyNode;
        int idx = 1;

        while(idx < left) {
            beforeNode = beforeNode->next;
            idx++;
        }

        ListNode* prev = nullptr;
        ListNode* curr = beforeNode->next;
        ListNode* tail = curr;
        ListNode* nextNode = curr->next;
        while(idx <= right) {
            nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
            idx++;
        }

        beforeNode->next = prev;
        tail->next = nextNode;

        return dummyNode.next;
    }
};