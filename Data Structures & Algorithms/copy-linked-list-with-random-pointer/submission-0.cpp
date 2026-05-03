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
        vector<Node*> newNodesAdressed; // invertedIndex
        unordered_map<Node*, int> originalNodesToPosition;
        Node dummyNode(0);

        Node* curr = head;
        Node* currCopy = &dummyNode;
        int i = 0;
        while (nullptr != curr) {
            originalNodesToPosition[curr] = i;

            Node* nextCopy = new Node(curr->val);
            newNodesAdressed.push_back(nextCopy);
            currCopy->next = nextCopy;
            currCopy = currCopy->next;
            
            curr = curr->next;
            i++;
        }

        curr = head;
        currCopy = dummyNode.next;

        while (nullptr != curr) {
            if (nullptr != curr->random) {
                int indexOfRandom = originalNodesToPosition[curr->random];
                currCopy->random = newNodesAdressed[indexOfRandom];
            }

            curr = curr->next;
            currCopy = currCopy->next;
        }

        return dummyNode.next; 
    }
};
