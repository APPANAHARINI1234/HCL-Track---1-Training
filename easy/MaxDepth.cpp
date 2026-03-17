struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(NULL), right(NULL) {}
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int maxdepth(TreeNode* root) {
        if (root == NULL) return 0;
        return 1 + max(maxdepth(root->left), maxdepth(root->right));
    }

    int maxDepth(TreeNode* root) {
        return maxdepth(root);
    }
};