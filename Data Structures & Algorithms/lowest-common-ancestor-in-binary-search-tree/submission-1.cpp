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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

        if (!p || !q) {
            return nullptr;
        }

        while (root) {
            bool pLess = p->val < root->val;
            bool qLess = q->val < root->val;
            if (
                (root == p || root == q) ||
                (pLess != qLess)
            )
            {
                return root;
            }
            if (pLess && qLess) {
                root = root->left;
            } else {
                root = root->right;
            }
        }
        return nullptr;
    }
};
