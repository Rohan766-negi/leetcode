class Solution {
public:
    ListNode* partition(ListNode* head, int x) {

        if(head == NULL || head->next == NULL) {
            return head;
        }

        ListNode* small = new ListNode(-1);
        ListNode* big = new ListNode(-1);

        ListNode* smallp = small;
        ListNode* bigp = big;

        ListNode* ntemp = head;

        while(ntemp != NULL) {

            ListNode* newNode = new ListNode(ntemp->val);

            if(ntemp->val < x) {
                smallp->next = newNode;
                smallp = smallp->next;
            }
            else {
                bigp->next = newNode;
                bigp = bigp->next;
            }

            ntemp = ntemp->next;
        }

        smallp->next = big->next;

        return small->next;
    }
};