/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (!node) return nullptr;

        unordered_map<Node*, Node*> oldToNew;
        queue<Node*> queue;

        oldToNew[node] = new Node(node->val);
        queue.push(node);

        while (!queue.empty()) {
            auto* origNode = queue.front();
            queue.pop();
            Node* copy = oldToNew[origNode];
            for (Node* nOrig: origNode->neighbors) {
                if(!oldToNew.contains(nOrig)) {
                    oldToNew[nOrig] = new Node(nOrig->val);
                    queue.push(nOrig);
                }
                copy->neighbors.push_back(oldToNew[nOrig]);
            }
        }
        return oldToNew[node];
    }
    // Node* cloneGraph(Node* node) {
    //     unordered_map<Node*, Node*> oldToNew;
    //     // return dfs(node, oldToNew);
    // }

    // Node* dfs(Node* node,  unordered_map<Node*, Node*>& oldToNew) {
    //     if (nullptr == node) {
    //         return nullptr;
    //     }
    //     if (oldToNew.contains(node)) {
    //         return oldToNew[node];
    //     }

    //     Node* copy = new Node(node->val);
    //     oldToNew[node] = copy;
    //     for (Node* neighbor: node->neighbors) {
    //         copy->neighbors.push_back(dfs(neighbor, oldToNew));
    //     }
    //     return copy;
    // }
};





