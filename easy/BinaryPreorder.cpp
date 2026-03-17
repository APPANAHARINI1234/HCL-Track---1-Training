class Solution {
public:
    void preorderHelper(TreeNode* root, vector<int>& order) {
        if (root == NULL) return;

        order.push_back(root->val);
        preorderHelper(root->left, order);
        preorderHelper(root->right, order);
    }

    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> preorder;
        preorderHelper(root, preorder);
        return preorder;
    }
};