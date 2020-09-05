#include <string>
#include <cstring>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

struct Trie{
    unordered_map<int,int>um;
    Trie* child[26];
    Trie(){
        memset(child, 0, sizeof(child));
    }
    ~Trie(){
        for(int i=0;i<26;i++){
            delete child[i];
        }
    }
    void insert(const char* str, int remain){
        if(str[0]=='\0'){
            um[0]++;
            return;
        }
        int indx = str[0]-'a';
        if(!child[indx]){
            child[indx] = new Trie();
        }
        um[remain]++;
        child[indx] -> insert(str+1, remain-1);
    }
    int find(const char* key, int remain){
        if(key[0]=='?'){
            return um[remain];
        }
        int indx = key[0]-'a';
        if(!child[indx])return 0;
        return child[indx]->find(key+1, remain-1);
    }
};

vector<int> solution(vector<string> words, vector<string> queries) {
    Trie* tr = new Trie();
    Trie* rtr = new Trie();
    
    int wlen = words.size();
    for(int i=0;i<wlen;i++){
        int leng = words[i].length();
        tr->insert(words[i].c_str(), leng);
        reverse(words[i].begin(), words[i].end());
        rtr->insert(words[i].c_str(), leng);
    }
    int qlen = queries.size();
    vector<int> answer(qlen);
    for(int i=0;i<qlen;i++){
        string q = queries[i];
        int cnt;
        if(q[0]=='?'){
            reverse(q.begin(), q.end());
            answer[i] = rtr->find(q.c_str(), q.length());
        }
        else{
            answer[i] = tr->find(q.c_str(), q.length());
        }
    }
    return answer;
}
