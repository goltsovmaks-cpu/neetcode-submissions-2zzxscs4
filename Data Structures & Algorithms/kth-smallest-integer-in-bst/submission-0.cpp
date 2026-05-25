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
    int kthSmallest(TreeNode* root, int k) {
        int startIndex = 0;
        return dfs(root, startIndex, k);
    }

    int dfs(
        TreeNode* root,
        int& index,
        int k)
    {
        if (nullptr == root) {
            return -1;
        }
        int leftResult = dfs(root->left, index, k);

        if (-1 != leftResult) {
            return leftResult;
        }
        index++;
        if (index == k) {
            return root->val;
        }

        return dfs(root->right, index, k);
    }

    // int dfs(TreeNode* root, int nodesBefore, int k, int& result) // -> count of nodes down
    // {
    //     if (nullptr == root) {
    //         return 0;
    //     }

    //     int leftChildsCount = dfs(root->left, nodesBefore, k, result);

    //     int currentNodeNumber = nodesBefore + leftChildsCount + 1;
    //     if (currentNodeNumber == k) {
    //         result = root->val;
    //     }
    //     if (currentNodeNumber >=k) {
    //         return currentNodeNumber;
    //     }

    //     return currentNodeNumber + dfs(root->right, currentNodeNumber, k, result);
    // }
};
