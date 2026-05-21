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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (nullptr == root) {
            return {};
        }
        vector<vector<int>> result;
        queue<TreeNode*> level;
        level.push(root);
        while (!level.empty()) {
            size_t width = level.size();
            
            result.push_back({});
            result.back().reserve(width);

            for (size_t i = 0; i < width; i++) {
                TreeNode* node = level.front();
                level.pop();
                result.back().push_back(node->val);
                if (nullptr != node->left) {
                    level.push(node->left);
                }
                if (nullptr != node->right) {
                    level.push(node->right);
                }
            }
        }
        return result;
    }
};
