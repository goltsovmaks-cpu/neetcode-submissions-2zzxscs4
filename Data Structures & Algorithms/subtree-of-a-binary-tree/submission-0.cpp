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
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (isEqualTrees(root, subRoot)) {
            return true;
        }
        if (nullptr == root) {
            return false;
        }
        return  isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }

    bool isEqualTrees(TreeNode* lhs, TreeNode* rhs) {
        if (nullptr == lhs && nullptr == rhs) {
            return true;
        } else if (nullptr == lhs || nullptr == rhs) {
            return false;
        }
        return 
            lhs->val == rhs->val && 
            isEqualTrees(lhs->left, rhs->left) &&
            isEqualTrees(lhs->right, rhs->right);
    }
};
