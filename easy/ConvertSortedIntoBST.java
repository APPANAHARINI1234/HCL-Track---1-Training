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
   
    public TreeNode mergesort(int[]nums, int low, int high){
        if(low > high)
          return null;
        int mid = low + (high - low)/2;
        TreeNode root = new TreeNode(nums[mid]);
        root.left = mergesort(nums, low, mid - 1);
        root.right = mergesort(nums, mid + 1, high);
        return root;
    }
    public TreeNode sortedArrayToBST(int[] nums) {
        return mergesort(nums, 0, nums.length - 1);
    }
}
// [0,1,2,3,4,5]
// mid = 3 insert it
// 0, 2           4, 5
// mid = 1        mid = 
// 0, 0        