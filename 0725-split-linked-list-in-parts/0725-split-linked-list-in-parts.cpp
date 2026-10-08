class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*> ans;

        ListNode* curr = head;
        int n = 0;

        while (curr != NULL) {
            n++;
            curr = curr->next;
        }

        int x = n % k;
        ListNode* temp = head;

        while (ans.size() < k) {

            int size = n / k;

            if (x > 0) {
                size++;
                x--;
            }

            if (size == 0) {
                ans.push_back(NULL);
                continue;
            }

            ans.push_back(temp);

            int y = 1;

            while (y < size) {
                temp = temp->next;
                y++;
            }

            ListNode* next = temp->next;
            temp->next = NULL;
            temp = next;
        }

        return ans;
    }
};