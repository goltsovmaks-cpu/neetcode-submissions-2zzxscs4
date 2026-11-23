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

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string result;
        serializeDfs(result, root);
        return result;
    }

    void serializeDfs(string& result, TreeNode* root)
    {
        if (nullptr == root) {
            result += 'N';
            return;
        }
        result += std::to_string(root->val) + ',';
        serializeDfs(result, root->left);
        result += ',';
        serializeDfs(result, root->right);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int pos = 0;
        return deserializeDfs(data, pos);
    }

    TreeNode* deserializeDfs(const string& data, int& pos)
    {
        if (pos >= data.size()) {
            return nullptr;
        }

        if (data[pos] == 'N') {
            pos += 2; // skip separator
            return nullptr;
        }

        int newPos = pos;
        while (data[newPos] != ',') {
            newPos++;
        }
        int value = std::stoi(data.substr(pos, newPos - pos));
        pos = newPos + 1;

        TreeNode* node = new TreeNode(value);
        node->left = deserializeDfs(data, pos);
        node->right = deserializeDfs(data, pos);
        return node;
    }
};















