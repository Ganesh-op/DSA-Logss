class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<int, vector<int>, greater<int>> minHeap;

        // Push all values from each list into the min heap
        for (auto list : lists) {
            while (list != nullptr) {
                minHeap.push(list->val);
                list = list->next;
            }
        }

        // Create dummy node and build the result list
        ListNode* dummy = new ListNode(0);
        ListNode* current = dummy;

        while (!minHeap.empty()) {
            current->next = new ListNode(minHeap.top());
            minHeap.pop();
            current = current->next;
        }

        return dummy->next;
    }
};