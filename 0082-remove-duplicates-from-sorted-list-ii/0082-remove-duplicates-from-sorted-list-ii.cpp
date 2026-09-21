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
    ListNode* deleteDuplicates(ListNode* head) {
        map<int, int> mp;
        ListNode* x = head;
        if(x==NULL){
            return head;
        }
        while (x->next != NULL) {
            if (x->val == x->next->val) {
                mp[x->val] = 1;
                x->next = x->next->next;

            } else
                x = x->next;
        }
        x = head;

        while (x->next != NULL) {
            if (mp[x->next->val] == 1) {
                x->next = x->next->next;
            } else {
                x = x->next;
            }
        }
        while (head != NULL && mp[head->val] == 1) {
            head = head->next;
        }

        return head;
    }
};