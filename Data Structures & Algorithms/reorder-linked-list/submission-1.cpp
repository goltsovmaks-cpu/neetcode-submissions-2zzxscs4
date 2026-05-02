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
    void reorderList(ListNode* head) {
        if (nullptr == head) {
            return;
        }

        // Split part
        int lenght = 0;
        ListNode* curr = head;
        while (curr) {
            curr = curr->next;
            lenght++;
        }
        int lenghtLeftPart = lenght - (lenght / 2);
        
        curr = head;
        for (int i = 1; i < lenghtLeftPart; i++) {
            curr = curr->next;
        }
        ListNode* right = curr->next;
        curr->next = nullptr; // remove link beetwen left and right parts.

        // Reverse right part.
        // curr = right;
        ListNode* prev = nullptr;

        while (right) {
            ListNode* temp = right->next;
            right->next = prev;
            prev = right;
            right = temp;
        }

        // while (curr) {
        //     ListNode* temp = curr->next;
        //     curr->next = prev;
        //     prev = curr;
        //     curr = temp;
        // }
        right = prev;

        // Merge part
        ListNode* left = head;
        while (right) {
            ListNode* tmp = left->next;
            left->next = right;
            right = right->next;
            left->next->next = tmp;
            left = left->next->next; 
        }
    }
};














