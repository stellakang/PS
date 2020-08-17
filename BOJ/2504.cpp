#include <iostream>
#include <string.h>
#include <stack>
#include <algorithm>
using namespace std;

int main(){
    char ch[35];
    cin>>ch;
    bool right = true;
    stack<char>st;
    int score = 0, tmp = 1;
    for(int i=0;i<strlen(ch);i++){
        if(ch[i]=='('){
            st.push('(');
            tmp*=2;
        }
        else if(ch[i]=='['){
            st.push('[');
            tmp*=3;
        }
        else if(ch[i]==')'){
            if(st.empty() || st.top()!='('){
                right = false;
                break;
            }
            st.pop();
            if(ch[i-1]=='('){
                score += tmp;
            }
            tmp/=2;
        }
        else{
            //']'
            if(st.empty() || st.top()!='['){
                right = false;
                break;
            }
            st.pop();
            if(ch[i-1]=='['){
                score += tmp;
            }
            tmp/=3;
        }
    }
    if(!st.empty() || right==false){
        cout<<0<<"\n";
    }
    else{
        cout<<score<<"\n";
    }
    return 0;
}

