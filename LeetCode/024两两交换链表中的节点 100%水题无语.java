/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {

    public ListNode swapPairs(ListNode head) {
        if(head==null)return null;
        ListNode phead = head.next==null?head:head.next;
        ListNode left = head, right = head.next, pre = null, next;
        while(left!=null&&right!=null){
            next = right.next;
            if(pre!=null)pre.next = right;
            pre = left;
            right.next = left;
            left.next = next;
            left = next;
            if(left!=null)right = left.next;
        }
        return phead;
    }
}