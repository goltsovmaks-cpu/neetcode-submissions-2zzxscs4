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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> inorderMap;
        inorderMap.reserve(inorder.size());

        for (int i = 0; i < inorder.size(); i++) {
            inorderMap[inorder[i]] = i;
        }

        int idx = 0;
        return dfs(preorder, idx, inorderMap, 0, preorder.size());
    }
private:
    TreeNode* dfs(
        const vector<int>& preorder,
        int& idx,
        const unordered_map<int, int>& inorderMap,
        int l,
        int r)
    {
        if (preorder.size() == idx) {
            return nullptr;
        }

        int val = preorder[idx];
        int inorderIdx = inorderMap.at(val);

        if (inorderIdx < l || inorderIdx >=r) {
            return nullptr;
        }

        TreeNode* node = new TreeNode(val);
        idx++;
        node->left = dfs(preorder, idx, inorderMap, l, inorderIdx);
        node->right = dfs(preorder, idx, inorderMap, inorderIdx+1, r);

        return node;
    }
};










