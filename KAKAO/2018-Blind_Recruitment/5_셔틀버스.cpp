#include <string>
#include <vector>
#include <algorithm>
#include <deque>
using namespace std;

struct clock{
    int hour, minute;
};
bool comp(struct clock& a, struct clock& b){
    if(a.hour==b.hour)return a.minute<b.minute;
    return a.hour<b.hour;
}
string solution(int n, int t, int m, vector<string> timetable) {
    string answer = "";
    deque<struct clock>crews;
    for(int i=0;i<timetable.size();i++){
        string t = timetable[i];
        int hour = (t[0]-'0')*10 + (t[1]-'0');
        int minute = (t[3]-'0')*10 + (t[4]-'0');
        crews.push_back({hour, minute});
    }
    sort(crews.begin(), crews.end(), comp);
    struct clock curTime = {9, 0};
    struct clock lastCrew;
    for(int i=0;i<n;i++){
        int count = 0;
        lastCrew = curTime;
        while(!crews.empty() && count<m){
            struct clock cr = crews.front();
            if(!(cr.hour<curTime.hour || (cr.hour==curTime.hour && cr.minute<=curTime.minute)))break;
            crews.pop_front();
            if(++count==m){
                lastCrew = cr;
                if(--lastCrew.minute<0){
                    lastCrew.minute += 60;
                    lastCrew.hour--;
                }
            }
        }
        curTime.minute += t;
        if(curTime.minute>=60){
            curTime.hour++;
            curTime.minute -= 60;
        }
    }
    answer = ((lastCrew.hour/10)+'0');
    answer += (lastCrew.hour%10)+'0';
    answer += ':';
    answer += ((lastCrew.minute/10)+'0');
    answer += (lastCrew.minute%10)+'0';
    return answer;
}
