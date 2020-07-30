#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* removeElements(ListNode* head, int val){
    if(head==NULL)return head;
    ListNode* node = head;
    while(node->next!=NULL){
        
        if(node->next->val==val)
            node->next=node->next->next;
        else
            node=node->next;
    }
    if(head->val==val)
        return head->next;
    return head;
}

