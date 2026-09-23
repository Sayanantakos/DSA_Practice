//Recursive Approach

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        // Base case: empty list or single node
        if (head == nullptr || head->next == nullptr) {
            return head;
        }

        ListNode* newHead = reverseList(head->next);
        head->next->next = head; // Reverse pointer
        head->next = nullptr;    // Break old link

        return newHead;
    }
};