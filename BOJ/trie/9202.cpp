#include <iostream>
#include <vector>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;

int w, b;
bool visit[4][4];
bool exist[300005];
vector<string>board(4);
vector<string>dict;
struct Trie{
    Trie* next[26];
    int finish;
    Trie() : finish(-1){
        memset(this->next, 0, sizeof(this->next));
    }
    ~Trie(){
        for(int i=0;i<26;i++){
            if(this->next[i])
                delete this->next[i];
        }
    }
    void insert(string key, int i){
        Trie* curr = this;
        for(int i=0;i<key.length();i++){
            int indx = key[i] - 'A';
            if(!curr->next[indx]){
                curr->next[indx] = new Trie();
            }
            curr = curr->next[indx];
        }
        curr->finish = i;
    }
    void query(int i, int j){
        int alpha = board[i][j] - 'A';
        Trie* cur = this->next[alpha];
        if(cur->finish!=-1){
            exist[cur->finish] = true;
        }
        int dx[8] = {-1, 0, 1, 0, -1, -1, 1, 1};
        int dy[8] = {0, 1, 0, -1, -1, 1, 1, -1};
        for(int k=0; k<8; k++){
            int xi = i + dx[k];
            int yi = j + dy[k];
            if(xi<0 || yi<0 || xi>=4 || yi>=4) continue;
            int alpha = board[xi][yi] - 'A';
            if(!visit[xi][yi] && cur->next[alpha]){
                //visit check
                visit[xi][yi] = true;
                //query
                cur->query(xi, yi);
                visit[xi][yi] = false;
            }
        }
    }
};
void printResult(int w){
    int score = 0;
    int cnt = 0;
    string longest="";
    for(int i=0;i<w;i++){
        if(exist[i]){
            int len = dict[i].length();
            if(longest.length()==len){
                longest = min(dict[i], longest);
            }
            else if(longest.length()<len){
                longest = dict[i];
            }
            if(len==8){
                score += 11;
            }
            else if(len==7){
                score += 5;
            }
            else if(len==6){
                score += 3;
            }
            else if(len==5){
                score += 2;
            }
            else if(len>=3){
                score ++;
            }
            cnt++;
            exist[i] = false;
        }
    }
    cout<<score<<" "<<longest<<" "<<cnt<<"\n";
}
int main(){
    cin>>w;
    Trie *root = new Trie;
    for(int i=0;i<w;i++){
        string str;
        cin>>str;
        dict.push_back(str);
        root -> insert(str, i);
    }
    cin>>b;
    while(b--){
        for(int i=0;i<4;i++){
            cin>>board[i];
        }
        for(int i=0;i<4;i++){
            for(int j=0;j<4;j++){
                if(!root->next[board[i][j]-'A'])continue;
                visit[i][j] = true;
                root->query(i, j);
                visit[i][j] = false;
            }
        }
        printResult(w);
    }
    return 0;
}

