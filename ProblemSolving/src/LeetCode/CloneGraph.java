package LeetCode;

import java.util.*;

public class CloneGraph {

    public static void main(String[] args) {
        Node one = new Node(1);
        Node two = new Node(2);
        Node three = new Node(3);
        Node four = new Node(4);
        one.neighbors = List.of(two, four);
        two.neighbors = List.of(one, three);
        three.neighbors = List.of(two, four);
        four.neighbors = List.of(one, three);
        Node clonedGraph = cloneGraph(one);
        Node clonedGraph1 = cloneGraph(new Node(1, new ArrayList<>()));
        System.out.println("0");
    }

    // Time complexity: O(n*m), space complexity: O(n*m)
    static Map<Integer, Node> map = new HashMap<>();
    public static Node cloneGraph(Node node) {
        if(node == null){
            return null;
        }
        if(map.containsKey(node.val)){
            return map.get(node.val);
        }
        Node newNode = new Node(node.val, new ArrayList<>());
        map.put(node.val, newNode);
        for(Node neighbor: node.neighbors){
            newNode.neighbors.add(cloneGraph(neighbor));
        }

        return newNode;
    }

    static class Node {
        public int val;
        public List<Node> neighbors;
        public Node() {
            val = 0;
            neighbors = new ArrayList<Node>();
        }
        public Node(int _val) {
            val = _val;
            neighbors = new ArrayList<Node>();
        }
        public Node(int _val, ArrayList<Node> _neighbors) {
            val = _val;
            neighbors = _neighbors;
        }
    }

}
