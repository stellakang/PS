#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>
#include <unordered_map>
#define SIZE 10005
using namespace std;

struct Trie{
    int count;
    Trie* child[26];
    Trie(){
        count = 0;
        memset(child, 0, sizeof(child));
    }
    ~Trie(){
        for(int i=0;i<26;i++){
            delete child[i];
        }
    }
    void insert(const char* str){
        if(str[0]=='\0'){
            return;
        }
        count++;
        int indx = str[0]-'a';
        if(!child[indx]){
            child[indx] = new Trie();
        }
        child[indx] -> insert(str+1);
    }
    int find(const char* key){
        if(key[0]=='?'){
            return count;
        }
        int indx = key[0]-'a';
        if(!child[indx])return 0;
        return child[indx]->find(key+1);
    }
};
Trie* tr[SIZE];
Trie* rtr[SIZE];
vector<int> solution(vector<string> words, vector<string> queries) {
    int sz = words.size();
    for(int i=0;i<sz;i++){
        int len = words[i].length();
        if(tr[len]==0){
            tr[len] = new Trie();
            rtr[len] = new Trie();
        }
        tr[len]->insert(words[i].c_str());
        reverse(words[i].begin(), words[i].end());
        rtr[len]->insert(words[i].c_str());
    }
    sz = queries.size();
    vector<int>answer(sz);
    for(int i=0;i<sz;i++){
        int len = queries[i].length();
        if(queries[i][0]=='?'){
            if(rtr[len]==0){
                answer[i] = 0;
                continue;
            }
            reverse(queries[i].begin(), queries[i].end());
            answer[i] = rtr[len]->find(queries[i].c_str());
        }
        else{
            if(tr[len]==0){
                answer[i] = 0;
                continue;
            }
            answer[i] = tr[len]->find(queries[i].c_str());
        }
    }
    return answer;
}
