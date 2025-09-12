class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;
        postorder(root, result);
        return result;
    }

    void postorder(TreeNode* node, vector<int>& res) {
        if (!node) return;
        postorder(node->left, res);
        postorder(node->right, res);
        res.push_back(node->val);
    }
};