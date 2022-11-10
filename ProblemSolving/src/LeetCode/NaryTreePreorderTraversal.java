package LeetCode;


import java.util.*;

public class NaryTreePreorderTraversal {

    public static class Node {
        public int val;
        public List<Node> children;

        public Node() {}

        public Node(int _val) {
            val = _val;
        }

        public Node(int _val, List<Node> _children) {
            val = _val;
            children = _children;
        }
    };


    public static void main(String[] args) {

        Node two = new Node(2, Collections.emptyList());

        Node four = new Node(4, Collections.emptyList());
        Node five = new Node(5, Collections.emptyList());
        Node six = new Node(6, Collections.emptyList());
        Node three = new Node(3, List.of(five, six));
        Node one = new Node(1, List.of(three, two, four));

        System.out.println(preorder(one));
    }

    public static List<Integer> preorder(Node root) {
        List<Integer> res = new ArrayList<>();
        visit(root, res);
        return res;
    }

    private static void visit(Node root, List<Integer> res){
        if(root==null)
            return;
        res.add(root.val);

        for(Node node: root.children){
            visit(node, res);
        }
    }
}
