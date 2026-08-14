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
int big(ListNode*head){
    int n=0;
    while(head!=NULL){
 n=n+1;
     head=head->next;
    }
    return n;
}
    ListNode*  add(ListNode*l1,ListNode*l2){
    int n=big(l1);
    int m=big(l2);
    ListNode*temp1=l1;
    ListNode*temp2=l2;
    ListNode*last=NULL;
    int carry=0;
    if(n>=m){
        while(l2!=NULL){
            int s=l1->val+l2->val+carry;
            
            carry=s/10;
            s=s%10;
            l1->val=s;
              last=l1;
            l1=l1->next;
            l2=l2->next;

        }
        while(l1!=NULL){
            int s=l1->val+carry;
            carry=s/10;
            s=s%10;
            l1->val=s;
            last=l1;
             l1=l1->next;


        }
        if(carry!=0){
            ListNode*tem=new ListNode(carry);
            

           if(last != nullptr) { last->next=tem;}

           else l1=tem;
             
        }
        return temp1;
    }
             else
{
             while(l1!=NULL){
            int s=l1->val+l2->val+carry;
            
            carry=s/10;
            s=s%10;
            l2->val=s;
            last = l2;   
            l1=l1->next;
            l2=l2->next;

             }
             while(l2!=NULL){
            int s=l2->val+carry;
            carry=s/10;
            s=s%10;
            l2->val=s;
            last=l2;
             l2=l2->next;


        }
        if(carry!=0){
            ListNode*tem=new ListNode(carry);
            

           if(last != nullptr) { last->next=tem;}
           
    

          
             
        }


}

             return temp2;
        
          
    
}

  

public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

   


          
          return  add(l1,l2);
            
         

    }
};