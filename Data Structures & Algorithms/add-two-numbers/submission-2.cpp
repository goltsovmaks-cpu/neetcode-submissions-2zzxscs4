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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode dummyHead = ListNode{};
        ListNode* curr = &dummyHead;

        bool overLoad = false;
        while (nullptr != l1 || nullptr != l2) {
            int sum = 0; 
            int l1Val = 0;
            int l2Val = 0;
            if (nullptr != l1) {
                l1Val = l1->val;
                l1 = l1->next;
            }
            if (nullptr != l2) {
                l2Val = l2->val;
                l2 = l2->next;
            }
            sum = overLoad ? 1 : 0;
            overLoad = false;
            sum += l1Val + l2Val;
            overLoad = sum / 10;
            sum = sum % 10;

            curr->next = new ListNode(sum);
            curr = curr->next;
        }
        if (overLoad) {
            curr->next = new ListNode(1);
        }
        return dummyHead.next;
    }
};
