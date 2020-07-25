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
    bool isPalindrome(ListNode* head) {
        vector<int>numbers;
        while(head){
            numbers.push_back(head->val);
            head=head->next;
        }
        
        int sz=numbers.size();
        for(int i=0;i<sz/2;i++){
            if(numbers[i]!=numbers[sz-i-1])return false;
        }
        return true;
    }
};
