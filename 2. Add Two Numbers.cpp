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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
    {
        ListNode* ans=new ListNode();//head of ans linked list
       
        int carry=0;//to store carry
        ans->val=(l1->val +l2->val+carry)%10;
        carry=(l1->val +l2->val+carry)/10;
        ListNode *ptr=ans;//pointer to track last element of ans linked list
        l1=l1->next; l2=l2->next;
        
        while(l1!=nullptr && l2!=nullptr)
        {
            ListNode* t=new ListNode();
            t->val=(l1->val +l2->val+carry)%10;
            carry=(l1->val +l2->val+carry)/10;
            t->next=nullptr;
            ptr->next=t;
             l1=l1->next; l2=l2->next;ptr=t;
        }
        if(l1==nullptr && l2!=nullptr)
        {//if l2 is longer list
            while(l2!=nullptr)
            {
                ListNode* t=new ListNode();
                t->val=(l2->val+carry)%10;
                carry=(l2->val+carry)/10;
                t->next=nullptr;
                ptr->next=t;
                l2=l2->next;ptr=t;
                
            }
        }
        else if(l1!=nullptr && l2==nullptr)
        {//if l1 is longer list
            while(l1!=nullptr)
            {
                ListNode* t=new ListNode();
                t->val=(l1->val+carry)%10;
                carry=(l1->val+carry)/10;
                t->next=nullptr;
                ptr->next=t;
                l1=l1->next;ptr=t;
                
            }
        }
        if(carry!=0)
        {//check for carry at the end
            ListNode* t=new ListNode();
            t->val=carry;
            t->next=nullptr;
            ptr->next=t;  
        }
        return ans;
        
    }
};