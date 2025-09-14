class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (!root) return false;

        // Check if it's a leaf node
        if (!root->left && !root->right)
            return root->val == targetSum;

        // Recurse on left and right subtrees
        int remaining = targetSum - root->val;
        return hasPathSum(root->left, remaining) || hasPathSum(root->right, remaining);
    }
};