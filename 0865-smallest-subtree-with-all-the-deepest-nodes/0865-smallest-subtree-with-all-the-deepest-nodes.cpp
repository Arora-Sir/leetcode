/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        int d = maxDepth(root);
        return find(root, 1, d);
    }

private:
    int maxDepth(TreeNode* root) {
        if (!root)
            return 0;
        return 1 + max(maxDepth(root->left), maxDepth(root->right));
    }

    TreeNode* find(TreeNode* root, int depth, int maxD) {
        if (!root)
            return nullptr;
        if (depth == maxD)
            return root;

        TreeNode* left = find(root->left, depth + 1, maxD);
        TreeNode* right = find(root->right, depth + 1, maxD);

        if (left && right)
            return root;
        return left ? left : right;
    }
};