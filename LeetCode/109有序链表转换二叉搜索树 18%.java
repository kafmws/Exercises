/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
class Solution {
    
    private List<Integer> num = new ArrayList<>();

    private TreeNode createTree(int begin, int end){//[begin, end]
        if(begin>end)return null;
        TreeNode root = null;
        int index = (begin+end)/2;
        Integer val = num.get(index);
        num.set(index,null);
        if(val!=null) {
            root= new TreeNode(val);
            root.left = createTree(begin,index-1);
            root.right = createTree(index+1,end);
        }
        return root;
    }

    public TreeNode sortedListToBST(ListNode head) {
        while(head!=null){
            num.add(head.val);
            head = head.next;
        }
        return createTree(0, num.size()-1);
    }
}