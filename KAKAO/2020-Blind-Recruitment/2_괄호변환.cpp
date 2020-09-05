#include <string>
#include <vector>
using namespace std;

string solution(string p) {
    //빈문자열이면 return
    if(p.length()==0)return "";
    //처음부터 탐색
    int r=0;
    bool isRight = true;
    for(int i=0;i<p.length();i++){
        if(p[i]=='(')r++;
        else if(p[i]==')')r--;
        if(r<0){
            isRight = false;
        }
        else if(r==0){
            string u = p.substr(0,i+1);
            string v = p.substr(i+1);
            if(isRight){
                //올바른 괄호문자열
                return u + solution(v);
            }
            //올바르지않은 괄호문자열
            string res = "("+solution(v)+")";
            for(int j=1;j<u.length()-1;j++){
                u[j] = u[j]=='('? ')':'(';
            }
            return res + u.substr(1, u.length()-2);
        }
    }
}
