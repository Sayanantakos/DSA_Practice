/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode dummy(0, head);
        ListNode* fast = &dummy;
        ListNode* slow = &dummy;

        // Advance fast pointer n + 1 steps
        for (int i = 0; i <= n; ++i) {
            fast = fast->next;
        }

        // Move fast to the end, maintaining the gap
        while (fast != nullptr) {
            fast = fast->next;
            slow = slow->next;
        }

        // Skip the target node
        ListNode* nodeToDelete = slow->next;
        slow->next = slow->next->next;
        delete nodeToDelete; // Free memory in C++

        return dummy.next;
    }
};