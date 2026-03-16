import java.util.ArrayList;
import java.util.List;
 //* Definition for a binary tree node.
  public class BinaryTreeInorderTraversals {
      int val;
      BinaryTreeInorderTraversals left;
      BinaryTreeInorderTraversals right;
      BinaryTreeInorderTraversals() {}
      BinaryTreeInorderTraversals(int val) { this.val = val; }
      BinaryTreeInorderTraversals(int val, BinaryTreeInorderTraversals left, BinaryTreeInorderTraversals right) {
          this.val = val;
          this.left = left;
          this.right = right;
      }
  }

class Solution {
    public void inordertraversal(BinaryTreeInorderTraversals root, List<Integer>inorder){
        if(root == null)
          return;
        inordertraversal(root.left, inorder);
        inorder.add(root.val);
        inordertraversal(root.right, inorder);
    }
    public List<Integer> inorderTraversal(BinaryTreeInorderTraversals root) {
        List<Integer>inorder = new ArrayList<>();
        inordertraversal(root, inorder);
        return inorder;
    }
}