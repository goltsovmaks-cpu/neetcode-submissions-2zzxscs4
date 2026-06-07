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
    int maxPathSum(TreeNode* root) {
        int globalMax = INT_MIN;
        dfs(root, globalMax);
        return globalMax;
    }

    int dfs(TreeNode* root, int& globalMax) {
        if (nullptr == root) {
            return 0;
        }
        int l = dfs(root->left, globalMax);
        int r = dfs(root->right, globalMax);
        int val = root->val;

        int crntMax = max({
            l + val,
            r + val,
            val});

        globalMax = max({
            globalMax,
            crntMax,
            l + val + r});

        return crntMax;
    }
};
