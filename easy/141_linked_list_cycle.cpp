/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* first=head,*second;
        if(first)
            second=first->next;
        else
            return false;
        
        while(first!=NULL && second!=NULL){
            if(first==second)return true;
            first=first->next;
            if(second->next)
                second=second->next->next;
            else
                break;
        }
        return false;
    }
};
