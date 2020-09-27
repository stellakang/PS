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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int cnt = 1;
        ListNode* leader = head; 
        ListNode* follower = head;
        ListNode* prev = head;
        
        // leader is n-1 after follower
        while(cnt<n){
            leader = leader ->next;
            cnt++;
        }
        
        // while leader cannot go
        while(leader-> next != NULL){
            leader = leader -> next;
            prev = follower;
            follower = follower -> next;
        }
        
        if(prev == follower)
            return head->next;
        
        prev ->next = follower->next;
        return head;
    }
};
