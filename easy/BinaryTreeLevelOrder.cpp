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
    public List<List<Integer>> levelOrder(TreeNode root) {
        List<List<Integer>>levelorder = new ArrayList<>();
        if(root == null)
          return levelorder;
        int level = 0;
        Queue<TreeNode>queue = new LinkedList<>();
        List<Integer>list = new ArrayList<>();
        queue.offer(root);
        list.add(root.val);
        while(!queue.isEmpty()){
          levelorder.add(new ArrayList<>(list));
          list.clear();
          int size = queue.size();
          while(size -- > 0){
            TreeNode par = queue.poll();
            if(par != null){
                if(par.left != null){
                    list.add(par.left.val);
                    queue.offer(par.left);
                }
                if(par.right != null){
                    list.add(par.right.val);
                    queue.offer(par.right);
                }
            }
          }
           
        }
        return levelorder;
    }
}