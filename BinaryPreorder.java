/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    public void preordertraversal(TreeNode root, List<Integer>order){
        if(root == null)
         return;
         order.add(root.val);
         preordertraversal(root.left, order);
         preordertraversal(root.right, order);
    }
    public List<Integer> preorderTraversal(TreeNode root) {
        List<Integer>preorder = new ArrayList<>();
        preordertraversal(root, preorder);
        return preorder;
    }
}