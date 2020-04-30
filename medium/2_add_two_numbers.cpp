class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *ans = l1;
        int carry=0;
            
        while(true){
            if(l1==NULL && l2==NULL && carry==0)
                break;
            int firstnum=0,secondnum=0;
            ListNode tmp(0);
            if(l1!=NULL)
                firstnum=l1->val;
            else
                l1=&tmp;   
            if(l2!=NULL)secondnum=l2->val;
            if(firstnum+secondnum>=10){
                carry=1;
                l1->val = (firstnum+secondnum)%10;
            }
            else{
                carry=0;
                l1->val = firstnum+secondnum;
            }   
            l1=l1->next;
            l2=l2->next;
        }
        return ans;
    }
};
