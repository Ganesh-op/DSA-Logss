class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (!head || left == right) return head;

        ListNode dummy(0);
        dummy.next = head;
        ListNode* beforeLeft = &dummy;

        // step 1: move beforeLeft just before the 'left' node
        for (int i = 1; i < left; i++) {
            beforeLeft = beforeLeft->next;
        }

        // step 2: start reversing
        ListNode* prev = nullptr;
        ListNode* curr = beforeLeft->next;
        for (int i = 0; i <= right - left; i++) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        // step 3: reconnect
        beforeLeft->next->next = curr; // tail connects to remainder
        beforeLeft->next = prev;       // beforeLeft connects to new head

        return dummy.next;
    }
};