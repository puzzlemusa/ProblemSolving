package LeetCode;


public class LinkedListCycleII {

    public static class ListNode {
        int val;
        ListNode next;

        ListNode() {
        }

        ListNode(int val) {
            this.val = val;
        }

        ListNode(int val, ListNode next) {
            this.val = val;
            this.next = next;
        }
    }

    public static void main(String[] args) {
        ListNode one = new ListNode(1);
        ListNode two = new ListNode(2);
        ListNode three = new ListNode(3);
        ListNode four = new ListNode(4);

        three.next = four;
        two.next = three;
        one.next = two;

        ListNode result = detectCycle(one);

        System.out.println("asdf");
    }

    //https://leetcode.com/problems/linked-list-cycle-ii/solutions/1701128/c-java-python-slow-and-fast-image-explanation-beginner-friendly/
    public static ListNode detectCycle(ListNode head) {
        ListNode sP = head;
        ListNode fP = head;

        while(fP != null && fP.next != null){
            fP = fP.next.next;
            sP = sP.next;
            if(sP==fP){
                ListNode hP = head;
                while(hP!=sP){
                    sP = sP.next;
                    hP = hP.next;
                }
                return hP;
            }
        }

        return null;
    }
}
