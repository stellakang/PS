#include <iostream>
#include <stdio.h>
#include <cstring>
#include <algorithm>
#define MAXCHAR 95
using namespace std;
double total;
struct Trie{
    bool isFinish;
    double count;
    Trie* next[MAXCHAR];

    Trie(){
        isFinish = false;
        count = 0.0;
        memset(next, 0, sizeof(next));
    }
    ~Trie(){
        for(int i=0;i<MAXCHAR;i++){
            if(next[i]){
                delete next[i];
            }
        }
    }
    void insert(char* key){
        if(*key == '\0'){
            isFinish = true;
            count += 1.0;
            return ;
        }
        int indx = *key - 32;
        if(!next[indx]){
            next[indx] = new Trie();
        }
        next[indx]->insert(key+1);
    }
    void print(string key){
        if(isFinish){
            cout<<fixed;
            cout.precision(4);
            cout<<key<<" "<<count/total*100<<"\n";
        }
        for(int i=0;i<MAXCHAR;i++){
            if(next[i]){
                char ch = 32+i;
                next[i]->print(key+ch);
            }
        }
    }
};

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    Trie* tr = new Trie();
    
    while(true){
        char str[35];
        cin.getline(str, 34);
        if(cin.eof())break;
        total += 1.0;
        tr->insert(str);
    }
    string str;
    tr->print(str);
    return 0;
}


