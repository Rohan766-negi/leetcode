class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {

        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        ListNode* x = dummy;
        ListNode* y = head;

        bool duplicate = false;

        while (y != NULL) {

            if (y->next != NULL && y->val == y->next->val) {
                duplicate = true;
            }
            else {
                if (duplicate) {
                    x->next = y->next;
                    duplicate = false;
                }
                else {
                    x = y;
                }
            }

            y = y->next;
        }

        return dummy->next;
    }
};