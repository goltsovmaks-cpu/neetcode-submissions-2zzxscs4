/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*> originToCopy;
        Node dummyNode(0);

        Node* curr = head;
        Node* currCopy = &dummyNode;
        int i = 0;
        while (nullptr != curr) {
            Node* nextCopy = new Node(curr->val);
            originToCopy[curr] = nextCopy;

            currCopy->next = nextCopy;

            currCopy = currCopy->next;
            curr = curr->next;

            i++;
        }

        curr = head;
        currCopy = dummyNode.next;

        while (nullptr != curr) {
            if (nullptr != curr->random) {
                currCopy->random = originToCopy[curr->random];
            }
            curr = curr->next;
            currCopy = currCopy->next;
        }

        return dummyNode.next; 
    }
};
