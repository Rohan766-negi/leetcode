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
    void reorderList(ListNode* head) {
        ListNode* last=head;
        ListNode* first=head;

        while(last->next!=NULL&&last->next->next!=NULL){
            first=first->next;
            last=last->next->next;
        }

         ListNode* curr=first->next;
         first->next=NULL;
          ListNode* prev=NULL;

          while(curr!=NULL){
               ListNode* nxt=curr->next;
               curr->next=prev;
               prev=curr;
               curr=nxt;
          }
          
           ListNode* st=head;

           while(prev!=NULL){
              
                ListNode* temp1=st->next;
                ListNode* temp2=prev->next;
                st->next=prev;
                prev->next=temp1;
                st = temp1;
                prev = temp2;



           }

         



    }
};