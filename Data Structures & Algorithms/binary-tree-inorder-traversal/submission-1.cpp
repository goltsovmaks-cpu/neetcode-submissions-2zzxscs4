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
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*> stack;
        TreeNode* curr = root;
        vector<int> result;
        while (curr || !stack.empty()) {
            if (curr) {
                stack.push(curr);
                curr = curr->left;
            } else {
                curr = stack.top();
                stack.pop();
                result.push_back(curr->val);
                curr = curr->right;
            }
        }
        return result;
    }
    // vector<int> inorderTraversal(TreeNode* root) {
    //     vector<int> inorder;
    //     dfs(root, inorder);
    //     return inorder;
    // }

    // void dfs(TreeNode* root, vector<int>& inorder) {
    //     if (nullptr == root) {
    //         return;
    //     }
    //     dfs(root->left, inorder);
    //     inorder.push_back(root->val);
    //     dfs(root->right, inorder);
    // }
};