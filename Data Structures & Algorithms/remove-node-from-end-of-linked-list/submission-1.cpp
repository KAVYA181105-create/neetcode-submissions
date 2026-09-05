class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode dummy(0);
        dummy.next = head;

        ListNode* fast = &dummy;
        ListNode* slow = &dummy;

        // Move fast n+1 steps
        for (int i = 0; i <= n; i++) {
            fast = fast->next;
        }

        // Move both until fast reaches nullptr
        while (fast != nullptr) {
            fast = fast->next;
            slow = slow->next;
        }

        // Delete nth node from the end
        ListNode* temp = slow->next;
        slow->next = slow->next->next;
        delete temp;

        return dummy.next;
    }
};