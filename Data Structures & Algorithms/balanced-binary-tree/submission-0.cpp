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
    bool isBalanced(TreeNode* root) {
        IsBalanced_ = true;
        findDepth(root);
        return IsBalanced_;
    }

    int findDepth(TreeNode* root) {
        if (nullptr == root || !IsBalanced_) {
            return 0;
        }
        int l = findDepth(root->left);
        int r = findDepth(root->right);
        if (abs(l - r) > 1) {
            IsBalanced_ = false;
        }
        return max(l, r) + 1;
    }
private:
    bool IsBalanced_ = true;
};
