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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (nullptr == root) {
            return root;
        }

        if (root->val < key) {
            root->right = deleteNode(root->right, key);
            return root;
        } else if (root->val > key) {
            root->left = deleteNode(root->left, key);
            return root;
        }

        TreeNode* leftChild = root->left;
        TreeNode* rightChild = root->right;
        delete root;

        if (nullptr == leftChild) {
            return rightChild;
        } else if (nullptr == rightChild) {
            return leftChild;
        };

        TreeNode* curr = rightChild;
        while (curr->left) {
            curr = curr->left;
        }
        curr->left = leftChild;

        return rightChild;
    }
};










