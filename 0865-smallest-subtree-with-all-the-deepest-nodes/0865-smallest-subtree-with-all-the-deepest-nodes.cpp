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

// Two-Pass DFS Approach -> Finding the maxDepth of Tree -> Finding max Depth
// Parent
//  class Solution {
//  public:
//      TreeNode* subtreeWithAllDeepest(TreeNode* root) {
//          int d = maxDepth(root);
//          return find(root, 1, d);
//      }

// private:
//     int maxDepth(TreeNode* root) {
//         if (!root)
//             return 0;
//         return 1 + max(maxDepth(root->left), maxDepth(root->right));
//     }

//     TreeNode* find(TreeNode* root, int depth, int maxD) {
//         if (!root) return nullptr;
//         if (depth == maxD) return root;

//         TreeNode* left = find(root->left, depth + 1, maxD);
//         TreeNode* right = find(root->right, depth + 1, maxD);

//         if (left && right) return root;
//         return left ? left : right;
//     }
// };

// Single Pass DFS Approach: Finding max depth and root along with it
// Bottom-Up approach
class Solution {
public:
    TreeNode* subtreeWithAllDeepest(TreeNode* root) { 
        return dfs(root).second;
    }

private:
    pair<int, TreeNode*> dfs(TreeNode* root) {
        if (!root) return {0, nullptr}; // depth 0 for empty tree (bottoms up approach: start from bottom with 0 depth of the left most child's child which doesn't exist)

        auto left = dfs(root->left);
        auto right = dfs(root->right);

        // Now left.first and right.first are ALREADY known depths
        // from the child subtrees

        if (left.first > right.first) // left subtree is deeper
            return {left.first + 1, left.second};

        if (right.first > left.first) // right subtree is deeper
            return {right.first + 1, right.second};

        return {left.first + 1, root}; // both sides have equal depth (first step depth start here on both sides of the tree while traversing)
    }
};