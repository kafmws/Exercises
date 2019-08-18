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

    List<List<TreeNode>> res = null;
    List<TreeNode> pre = null;

    void fromLeft2Right() {
        List<TreeNode> newFloor = new ArrayList<>();
        for(int i = pre.size()-1;i>=0;i--){
            TreeNode node = pre.get(i);
            if(node.left!=null)newFloor.add(node.left);
            if(node.right!=null)newFloor.add(node.right);
        }
        if(newFloor.size()==0)return;
        res.add(newFloor);
        pre = newFloor;
        fromRight2Left();
    }

    void fromRight2Left() {
        List<TreeNode> newFloor = new ArrayList<>();
        for(int i = pre.size()-1;i>=0;i--){
            TreeNode node = pre.get(i);
            if(node.right!=null)newFloor.add(node.right);
            if(node.left!=null)newFloor.add(node.left);
        }
        if(newFloor.size()==0)return;
        res.add(newFloor);
        pre = newFloor;
        fromLeft2Right();
    }

    public List<List<Integer>> zigzagLevelOrder(TreeNode root) {
        List<List<Integer>> re = new LinkedList<>();
        if(root==null)return re;
        res = new LinkedList<>();
        pre = new ArrayList<>();
        pre.add(root);
        res.add(pre);
        fromRight2Left();
        for(List<TreeNode> floor : res){
            List<Integer> integers = new ArrayList<>(floor.size());
            for(TreeNode node : floor){
                integers.add(node.val);
            }
            re.add(integers);
        }
        return re;
    }
    
}