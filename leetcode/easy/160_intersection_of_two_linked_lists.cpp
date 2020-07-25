/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#linear
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* first=headA, *second=headB;
        int cnt1=0,cnt2=0;
        while(first && second){
            if(first==second)return first;
            first=first->next;
            second=second->next;
            if(!first && cnt1==0){
                first=headB;
                cnt1++;
            }
            if(!second && cnt2==0){
                second=headA;
                cnt2++;
            }
        }
        return NULL;
    }
};

#hash map
class Solution2 {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        unordered_set<ListNode*>us;
        while(headA){
            us.insert(headA);
            headA=headA->next;
        }
        while(headB){
            if(us.find(headB)!=us.end())
                return headB;
            headB=headB->next;
        }
        return NULL;
    }
};

#brute-force
class Solution3 {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        for(auto first=headA;first!=NULL;first=first->next){
            for(auto second=headB;second!=NULL;second=second->next){
                if(first==second)return first;
            }
        }
        return NULL;
    }
};
