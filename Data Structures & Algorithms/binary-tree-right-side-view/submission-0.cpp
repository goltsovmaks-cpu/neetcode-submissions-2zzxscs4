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
    vector<int> rightSideView(TreeNode* root) {
        if (nullptr == root) {
            return {};
        }
        vector<int> result;
        queue<TreeNode*> level;
        level.push(root);

        while (!level.empty()) {
            size_t len = level.size();
            result.push_back(level.back()->val);
            for (size_t i = 0; i < len; ++i) {
                TreeNode* node = level.front();
                if (nullptr != node->left) {
                    level.push(node->left);
                }
                if (nullptr != node->right) {
                    level.push(node->right);
                }
                level.pop(); 
            }
        }
        return result;
    }
};









