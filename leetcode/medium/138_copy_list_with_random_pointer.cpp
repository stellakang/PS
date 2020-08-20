//solution1
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head==NULL)return NULL;
        Node* node = new Node(head->val);
        Node* tmpH = head;
        Node* tmpN = node;
        // next 
        while(tmpH->next!=NULL){
            tmpN->next = new Node(tmpH->next->val);
            tmpH = tmpH -> next;
            tmpN = tmpN->next;
        }
        // random
        tmpH = head;
        tmpN = node;
        while(tmpN!=NULL){
            Node* sH = head;
            Node* sN = node;
            while(sH != NULL){
                if(sH->random == tmpH){
                    sN->random = tmpN;
                }
                sH = sH->next;
                sN = sN->next;
            }
            tmpH= tmpH->next;
            tmpN = tmpN->next;
        }
        return node;
    }
};

//solution2
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head==NULL)return NULL;
        unordered_map<Node*, Node*>mapping;
        Node* node = new Node(head->val);
        mapping[head] = node;
        Node* tmp = head;
        Node* tmpNode = node;
        while(tmp->next!=NULL){
            tmpNode->next = new Node(tmp->next->val);
            mapping[tmp->next] = tmpNode->next;
            tmp = tmp->next;
            tmpNode = tmpNode->next;
        }
        tmp = head;
        tmpNode = node;
        while(tmp!=NULL){
            if(tmp->random != NULL){
                tmpNode->random = mapping[tmp->random];
            }
            else{
                tmpNode->random = NULL;
            }
            tmp = tmp->next;
            tmpNode = tmpNode->next;
        }
        return node;
    }
};
