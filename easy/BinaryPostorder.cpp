class Solution {
public:
    void postorderTraversalHelper(TreeNode* root, vector<int>& order) {
        if (root == NULL) return;

        postorderTraversalHelper(root->left, order);
        postorderTraversalHelper(root->right, order);
        order.push_back(root->val);
    }

    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> postorder;
        postorderTraversalHelper(root, postorder);
        return postorder;
    }
};