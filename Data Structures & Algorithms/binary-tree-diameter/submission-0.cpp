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
    int diameterOfBinaryTree(TreeNode* root) {
        int ans = 0;
        dfs(root, ans);
        return ans - 1;
    }

    int dfs(TreeNode* root, int& ans) { // find max deep + calculate the answer
        if (nullptr == root) {
            return 0;
        }
        int l = dfs(root->left, ans);
        int r = dfs(root->right, ans);

        ans = max(ans, l + 1 + r);
        return max(l, r) + 1;
    }
};
