#include <string>
#include <vector>
#include <deque>
#include <cmath>
#include <iostream>
#include <algorithm>
using namespace std;

struct times{
    long long endTime;
    long long process;
};
bool isOverlapped(times t1, times t2){
    if(t1.endTime-t1.process-1000+2<=t2.endTime)return true;
    return false;
}
int solution(vector<string> lines) {
    int sz = lines.size();
    vector<times>logs;
    for(string l: lines){
        long long sum = 0;
        sum += stoi(l.substr(11))*3600000;
        sum += stoi(l.substr(14))*60000;
        sum += stod(l.substr(17))*1000;
        long long process = stod(l.substr(24))*1000;
        logs.push_back({sum, process});
    }
    int answer = 0;
    for(int i=sz-1;i>=0;i--){
        int count = 0;
        for(int j=i;j<sz;j++){
            if(isOverlapped(logs[j], logs[i])){
                count ++;
            }
        }
        answer = max(answer, count);
    }
    return answer;
}
