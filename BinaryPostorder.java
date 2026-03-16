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
    public void postordertraversal(TreeNode root, List<Integer>order){
        if(root == null)
         return;
         postordertraversal(root.left, order);
         postordertraversal(root.right, order);
         order.add(root.val);
    }
    public List<Integer> postorderTraversal(TreeNode root) {
        List<Integer>postorder = new ArrayList<>();
        postordertraversal(root, postorder);
        return postorder;
    }
}