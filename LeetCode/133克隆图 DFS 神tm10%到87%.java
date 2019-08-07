/*
// Definition for a Node.
class Node {
    public int val;
    public List<Node> neighbors;

    public Node() {}

    public Node(int _val,List<Node> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/
class Solution {
    private Map<Node,Node> map = new LinkedHashMap<>();

    public Node cloneGraph(Node node) {
        if(map.containsKey(node)) return map.get(node);
        Node newNode = new Node();
        map.put(node,newNode);
        newNode.val = node.val;
        newNode.neighbors = new LinkedList<>();
        for (Node n : node.neighbors){
            newNode.neighbors.add(cloneGraph(n));
        }
        return newNode;
    }
}