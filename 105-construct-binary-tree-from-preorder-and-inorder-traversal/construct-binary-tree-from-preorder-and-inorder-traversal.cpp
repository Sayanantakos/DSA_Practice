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
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
private:
    int preorderIndex = 0;
    unordered_map<int, int> inorderIndexMap;

    TreeNode* arrayToTree(const vector<int>& preorder, int left, int right) {
        if (left > right) {
            return nullptr;
        }

        // Pick current root from preorder traversal
        int rootValue = preorder[preorderIndex++];
        TreeNode* root = new TreeNode(rootValue);

        // Find root index in inorder array to divide subtrees
        int inorderIndex = inorderIndexMap[rootValue];

        // Build left and right subtrees
        root->left = arrayToTree(preorder, left, inorderIndex - 1);
        root->right = arrayToTree(preorder, inorderIndex + 1, right);

        return root;
    }

public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        preorderIndex = 0;
        inorderIndexMap.clear();

        // Store value -> index mapping for O(1) lookups
        for (int i = 0; i < inorder.size(); ++i) {
            inorderIndexMap[inorder[i]] = i;
        }

        return arrayToTree(preorder, 0, inorder.size() - 1);
    }
};