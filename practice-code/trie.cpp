#include <iostream>
#include <vector>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;

struct Trie{
    Trie* next[26];
    bool finish;
    Trie() : finish(false){
        memset(this->next, 0, sizeof(this->next));
    }
    ~Trie(){
        for(int i=0;i<26;i++){
            if(this->next[i])
                delete this->next[i];
        }
    }
    void insert(string key){
        Trie* curr = this;
        for(int i=0;i<key.length();i++){
            int indx = key[i] - 'A';
            if(!curr->next[indx]){
                curr->next[indx] = new Trie();
            }
            curr = curr->next[indx];
        }
        curr->finish = true;
    }
    Trie* find(string key){
        Trie* curr = this;
        for(int i=0;i<key.length();i++){
            int indx = key[i] - 'A';
            if(!curr->next[indx]){
                return NULL;
            }
            curr = curr ->next[indx];
        }
        if(curr->finish)return curr;
        return NULL;
    }
};

int main(){
    Trie* root = new Trie;
    //input
    int datas;
    cin>>datas;
    while(datas--){
        string str;
        cin>>str;
        root->insert(str);
    }
    int findNum;
    cin>>findNum;
    while(findNum--){
        string str;
        cin>>str;
        if(root->find(str)!=NULL){
            cout<<str<<" found.\n";
        }
        else
        {
            cout<<str<<" not found.\n";
        }
    }
    return 0;
}
