/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode removeNthFromEnd(ListNode head, int n) {
        int length = 0;
        ListNode temp = head;
        while(temp != null){
            length ++;
            temp = temp.next;
        }
        int k = length - n;
        System.out.println(length+" "+k);
        if(k == 0)
          return head.next;
        int i = 0;
        temp = head;
        while(i <= k - 2){
            head = head.next;
            i ++;
        }
        head.next = head.next.next;
        return temp;
    }
}