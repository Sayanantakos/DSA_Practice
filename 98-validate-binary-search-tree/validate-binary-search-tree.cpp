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
#include <climits>

class Solution {
private:
    bool validate(TreeNode* node, long long minVal, long long maxVal) {
        if (!node) {
            return true;
        }

        // Current node value must lie strictly within (minVal, maxVal)
        if (node->val <= minVal || node->val >= maxVal) {
            return false;
        }

        // Validate left subtree (upper bound = node->val) and right subtree (lower bound = node->val)
        return validate(node->left, minVal, node->val) && validate(node->right, node->val, maxVal);
    }

public:
    bool isValidBST(TreeNode* root) {
        return validate(root, LLONG_MIN, LLONG_MAX);
    }
};