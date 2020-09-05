#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int len = s.length();
    int answer = len;
    for(int i=1;i<=len;i++){
        string prev = s.substr(0,i);
        string compress;
        int count = 1;
        for(int j=i;j<len;j+=i){
            string cur = s.substr(j, i);
            if(prev == cur){
                count ++;
            }
            else{
                compress += prev;
                if(count!=1)
                    compress += to_string(count);
                prev = cur;
                count = 1;
            }
        }
        compress += prev;
        if(count!=1)
            compress += to_string(count);
        if(compress.length()<answer){
            answer = compress.length();
        }
    }
    return answer;
}
