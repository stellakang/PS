#include <string>
#include <vector>
#include <deque>
#include <functional>
#include <algorithm>
using namespace std;

deque<int>wList;
int minimumP = 0x7fffffff;

void checkWeakPoint(int n, int dIndx, vector<int>&dist){
    int len = wList.size();
    int distSz = dist.size();
    if(len==0){
        minimumP = min(minimumP, dIndx);
        return;
    }
    if(dIndx==distSz)return;
    int d = min(n, dist[dIndx]);
    deque<int>save;
    for(int i=0;i<len;i++){
        int w = wList.front();
        while(!wList.empty()){
            int cur = wList.front();
            if((w+d>=cur && cur>=w) || (w+d>=n && w+d-n>=cur)){
                wList.pop_front();
                save.push_back(cur);
            }
            else break;
        }
        checkWeakPoint(n, dIndx+1, dist);
        while(!save.empty()){
            wList.push_front(save.back());
            save.pop_back();
        }
        wList.pop_front();
        wList.push_back(w);
    }
}

int solution(int n, vector<int> weak, vector<int> dist) {
    sort(dist.begin(), dist.end(), greater<int>());
    for(int i=0;i<weak.size();i++){
        wList.push_back(weak[i]);
    }
    checkWeakPoint(n, 0, dist);
    if(minimumP==0x7fffffff)return -1;
    return minimumP;
}
