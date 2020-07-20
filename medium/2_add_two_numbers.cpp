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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* num1=new ListNode(0,l1);
        ListNode* num2=new ListNode(0,l2);
        ListNode* res=new ListNode(0,l1);
        int sum=0;
        while(num1->next || num2->next || sum>0){
            if(num1->next)
                sum+=num1->next->val;
            else
                num1->next=new ListNode(0);
            if(num2->next)
                sum+=num2->next->val;
            num1->next->val=sum%10;
            num1=num1->next;
            if(num2->next)
                num2=num2->next;
            sum=sum/10;
        }
        return res->next;
    }
};


