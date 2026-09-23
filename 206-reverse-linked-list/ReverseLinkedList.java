//Recursive Approach

class Solution {
    public ListNode ReverseLinkedList(ListNode head) {
        // Base case: empty list or single node
        if (head == null || head.next == null) {
            return head;
        }

        ListNode newHead = ReverseLinkedList(head.next);
        head.next.next = head; // Reverse pointer
        head.next = null;       // Break old link

        return newHead;
    }
}