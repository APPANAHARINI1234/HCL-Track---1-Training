class Solution {
public:
    void inorderHelper(TreeNode* root, vector<int>& inorder) {
        if (root == NULL) return;

        inorderHelper(root->left, inorder);
        inorder.push_back(root->val);
        inorderHelper(root->right, inorder);
    }

    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> inorder;
        inorderHelper(root, inorder);
        return inorder;
    }
};