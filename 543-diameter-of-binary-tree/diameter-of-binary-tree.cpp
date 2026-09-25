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
private:
    int maxDiameter = 0;

    int getHeight(TreeNode* node) {
        if (!node) return 0;

        int leftHeight = getHeight(node->left);
        int rightHeight = getHeight(node->right);

        // Update the maximum diameter found so far
        maxDiameter = std::max(maxDiameter, leftHeight + rightHeight);

        // Return height of current node
        return 1 + std::max(leftHeight, rightHeight);
    }

public:
    int diameterOfBinaryTree(TreeNode* root) {
        maxDiameter = 0;
        getHeight(root);
        return maxDiameter;
    }
};