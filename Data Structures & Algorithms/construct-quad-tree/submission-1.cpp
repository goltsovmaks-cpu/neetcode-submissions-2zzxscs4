/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
public:
    Node* construct(vector<vector<int>>& grid) {
        if (grid.empty()) {
            return nullptr;
        }
        return dfs(grid, 0, 0, grid.size(), grid.size());
    }

    Node* dfs(
        vector<vector<int>>& grid,
        int upRow,
        int leftCol,
        int downBorder,
        int rightBorder)
    {
        Node* node = new Node();
        int count0 = 0;
        int count1 = 0;
        for (int row = upRow; row < downBorder; row++) {
            for (int col = leftCol; col < rightBorder; col++) {
                if (0 == grid[row][col]) {
                    count0++;
                } else {
                    count1++;
                }
            }

        }
        if (0 == count0) {
            node->val = true;
            node->isLeaf = true;
        } else if (0 == count1) {
            node->val = false;
            node->isLeaf = true;
        } else { 
            // node->val = false;
            // node->isLeaf = false;

            int middleRow = upRow + (downBorder - upRow) / 2;
            int middleCol = (leftCol + rightBorder) / 2;

            node->topLeft = dfs(grid, upRow, leftCol, middleRow, middleCol);
            node->bottomLeft = dfs(grid, middleRow, leftCol, downBorder, middleCol);

            node->topRight = dfs(grid, upRow, middleCol, middleRow, rightBorder);
            node->bottomRight = dfs(grid, middleRow, middleCol, downBorder, rightBorder);
        }

        return node;
    }
};











