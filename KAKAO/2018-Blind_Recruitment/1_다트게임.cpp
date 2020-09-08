#include <string>
#include <cmath>
using namespace std;

int solution(string dartResult) {
    int answer = 0;
    int len = dartResult.length();
    int cur = 0;//current index
    int prevScore = 0;
    for(int i=0;i<3;i++){
        int score = 0;
        for(int j=cur;j<len;j++){
            char c = dartResult[j];
            if(c>='0' && c<='9')score = score*10 + (int)(c-'0');
            if(c=='S' || c=='D' || c=='T'){
                if(c=='D')
                    score = pow(score,2);
                if(c=='T')
                    score = pow(score,3);
                int mul = 1;
                if(j+1<len && dartResult[j+1]=='*'){ 
                    answer += prevScore;
                    mul = 2;
                }
                if(j+1<len && dartResult[j+1]=='#'){
                    mul = -1;
                }
                answer += score*mul;
                prevScore = score*mul;
                cur=j+1;
                if(mul!=1)cur++;
                break;
            }
        }
    }
    return answer;
}
