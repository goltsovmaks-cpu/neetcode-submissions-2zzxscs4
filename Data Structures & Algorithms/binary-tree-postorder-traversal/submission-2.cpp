/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {

        vector<int> result;
        stack<pair<TreeNode*, bool>> stack;
        stack.emplace(root, false);

        while (!stack.empty()) {
            const auto& [node, visited] = stack.top();
            stack.pop();
            if (nullptr == node) {
                continue;
            }

            if (visited) {
                result.push_back(node->val);
            } else {
                stack.emplace(node, true);
                stack.emplace(node->right, false);
                stack.emplace(node->left, false);
            }
        }

        return result;
    }
    // vector<int> postorderTraversal(TreeNode* root) {
    //     vector<int> inorder;
    //     dfs(root, inorder);
    //     return inorder;
    // }

    // void dfs(TreeNode* root, vector<int>& inorder) {
    //     if (nullptr == root) {
    //         return;
    //     }
    //     dfs(root->left, inorder);
    //     dfs(root->right, inorder);
    //     inorder.push_back(root->val);
    // }
};