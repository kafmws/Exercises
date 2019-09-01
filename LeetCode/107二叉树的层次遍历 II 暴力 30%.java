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
    public List<List<Integer>> levelOrderBottom(TreeNode root) {
        List<List<Integer>> res = new LinkedList<>();
        if(root == null)return res;
        Queue<TreeNode> queue = new LinkedList<>();
        queue.offer(root);
        queue.offer(null);//flag of the ending of the floor
        List<Integer> floor = new ArrayList<>();
        while (!queue.isEmpty()){
            TreeNode node = queue.remove();
            if(node==null){
                res.add(0,floor);
                floor = new ArrayList<>();
                if(!queue.isEmpty())queue.offer(null);
                continue;
            }
            floor.add(node.val);
            if(node.left!=null)queue.offer(node.left);
            if(node.right!=null)queue.offer(node.right);
        }
        return res;
    }
}