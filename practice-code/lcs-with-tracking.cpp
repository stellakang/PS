#include <iostream>
#include <vector>
#include <stack>
#include <string.h>
#include <algorithm>
#define SIZE 10005

using namespace std;
int lcs[1005][1005];
int tr[1005][1005];
int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    char ch1[1005], ch2[1005];
    cin>>(ch1+1)>>(ch2+1);
    int len1 = strlen(ch1+1);
    int len2 = strlen(ch2+1);
    for(int i=1;i<=len1;i++){
        for(int j=1;j<=len2;j++){
            if(ch1[i]==ch2[j]){
                lcs[i][j] = lcs[i-1][j-1] + 1;
                tr[i][j] = 2;
            }
            else{
                if(lcs[i][j-1]>lcs[i-1][j]){
                    lcs[i][j] = lcs[i][j-1];
                    tr[i][j] = 1;
                }
                else{
                    lcs[i][j] = lcs[i-1][j];
                    tr[i][j] = 3;
                }
            }
        }
    }
    int x = len1, y = len2;
    stack<char>st;
    while(x>0 && y>0){
        if(tr[x][y]==2){
            st.push(ch2[y]);
            x--;
            y--;
        }
        else if(tr[x][y]==1){
            y--;
        }
        else
        {
            x--;
        }
    }
    cout<<lcs[len1][len2]<<"\n";
    while(!st.empty()){
        cout<<st.top();
        st.pop();
        
    }
    cout<<"\n";
    return 0;
}
