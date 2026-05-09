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
    // Use heap for easier solution.
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty()) {
            return nullptr;
        }
        vector<ListNode*> mergedNodes(lists);
        vector<ListNode*> temp;
        while(mergedNodes.size() > 1) {
            for (int i = 0; i < mergedNodes.size(); i+=2) {
                ListNode* first = mergedNodes[i];
                ListNode* second = i + 1 < mergedNodes.size() ? mergedNodes[i+1] : nullptr;
                temp.push_back(MergeToLists(first, second));
            }
            mergedNodes = std::move(temp);
            temp.clear();
        }
        return mergedNodes[0];
    }
    
    ListNode* MergeToLists(ListNode* first, ListNode* second) {
        ListNode dummyHead;
        ListNode* curr = &dummyHead;
        while (nullptr != first && second != nullptr) {
            if (first->val < second->val) {
                curr->next = first;
                first = first->next;
            } else {
                curr->next = second;
                second = second->next;
            }
            curr = curr->next;
        }

        curr->next = nullptr != first ? first : second;
        return dummyHead.next;
    }
};
