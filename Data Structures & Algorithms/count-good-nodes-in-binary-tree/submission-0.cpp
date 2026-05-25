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
    int goodNodes(TreeNode* root) {
        if (nullptr == root) {
            return 0;
        }
        return dfs(root, root->val);
    }

    int dfs(TreeNode* root, int currMax) {
        if (nullptr == root) {
            return 0;
        }
        if (root->val >= currMax) {
            return 1 + dfs(root->left, root->val) + dfs(root->right, root->val);
        } else {
            return dfs(root->left, currMax) + dfs(root->right, currMax);
        }
    }
};
