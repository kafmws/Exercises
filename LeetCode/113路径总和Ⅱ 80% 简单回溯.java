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

    private int[] tree = new int[10001];
    List<List<Integer>> res = new LinkedList<>();
    private int obj;
    private int currentSum = 0;

    private void re(TreeNode root, int depth){
        currentSum += root.val;
        tree[depth] = root.val;
        if(currentSum==obj&&root.right==null&&root.left==null){
            List<Integer> list = new ArrayList<>(depth+1);
            for(int i = 0;i<=depth;i++){
                list.add(tree[i]);
            }
            res.add(list);
        }
        if(root.right!=null)re(root.right, depth+1);
        if(root.left!=null)re(root.left, depth+1);
        currentSum -= root.val;
    }

    public List<List<Integer>> pathSum(TreeNode root, int sum) {
        obj = sum;
        if(root!=null) re(root,0);
        return res;
    }
}