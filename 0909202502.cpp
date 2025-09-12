class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* cur = head;
        while (cur && cur->next) {
            if (cur->val == cur->next->val) {
                cur->next = cur->next->next; // Duplicate mila, skip kar diya
            } else {
                cur = cur->next; // Aage badho
            }
        }
        return head;
    }
};