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
    int rob(TreeNode* root) {
        auto p = dfs(root);
        return max(p.first, p.second);
    }
    // pair<takeCurr, skipCurr>
    pair<int, int> dfs(TreeNode* root) {
        if (nullptr == root) {
            return pair{0,0};
        }
        auto l = dfs(root->left);
        auto r = dfs(root->right);

        int takeCurr = root->val + l.second + r.second;
        int skipCurr =
            max(l.first, l.second) +
            max(r.first, r.second);

        return pair{takeCurr, skipCurr};
    }
};