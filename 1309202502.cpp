class Solution {
public:
    int minDepth(TreeNode* root) {
        if (!root) return 0;

        // If one child is null, we must go through the other
        if (!root->left) return 1 + minDepth(root->right);
        if (!root->right) return 1 + minDepth(root->left);

        return 1 + min(minDepth(root->left), minDepth(root->right));
    }
};