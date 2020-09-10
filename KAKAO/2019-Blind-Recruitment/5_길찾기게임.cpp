#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
struct node{
    int val;
    int x;
    node* left;
    node* right;
    node(int v, int xpos){
        val = v;
        x = xpos;
        left = NULL;
        right = NULL;
    }
};
struct info{
    int val;
    int x,y;
};

using namespace std;

bool comp(info&a, info&b){
    return a.y>b.y;
}
void preorder(node* n, vector<vector<int>> &answer){
    answer[0].push_back(n->val);
    if(n->left!=NULL)
        preorder(n->left, answer);
    if(n->right!=NULL)
        preorder(n->right, answer);
}
void postorder(node* n, vector<vector<int>> &answer){
    if(n->left!=NULL)
        postorder(n->left, answer);
    if(n->right!=NULL)
        postorder(n->right, answer);
    answer[1].push_back(n->val);
}
vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
    vector<vector<int>> answer(2);
    vector<info>binary;
    for(int i=0;i<nodeinfo.size();i++){
        binary.push_back({i+1, nodeinfo[i][0], nodeinfo[i][1]});
    }
    sort(binary.begin(), binary.end(), comp);
    node* root = new node(binary[0].val, binary[0].x);
    for(int i=1;i<binary.size();i++){
        node* cur = root;
        info in = binary[i];
        while(true){
            if(cur->x > in.x){
                if(cur->left == NULL){
                    cur->left = new node(in.val, in.x);
                    break;
                }
                cur = cur->left;
            }
            else{
                if(cur->right == NULL){
                    cur->right = new node(in.val, in.x);
                    break;
                }
                cur = cur->right;
            }
        }
    }
    preorder(root, answer);
    postorder(root, answer);
    return answer;
}
