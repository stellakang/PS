#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstring>
using namespace std;

struct pos{
    int x,y;
};
bool comp(pos a, pos b){
    if(a.x==b.x){
        return a.y<b.y;
    }
    return a.x>b.x;
};
int update(vector<int>&seg, int node, int start, int end, int indx){
    if(indx < start || end < indx) return seg[node];
    if(start == end) return seg[node] += 1;
    int mid = (start+end)/2;
    int l = update(seg, node*2, start, mid, indx);
    int r = update(seg, node*2+1, mid+1, end, indx);
    return seg[node] = l + r;//sum segment tree
}
int query(vector<int>&seg, int node, int start, int end, int left, int right){
    if(right < start || end < left)return 0;
    if(left <= start && end <= right)return seg[node];
    int mid = (start+end)/2;
    int l = query(seg, node*2, start, mid, left, right);
    int r = query(seg, node*2+1, mid+1, end, left, right);
    return l+r;//sum segment tree
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int T;
    scanf("%d",&T);
    while(T--){
        int N;
        scanf("%d",&N);
        pos island[N];
        vector<int>yPos(N);
        for(int i=0;i<N;i++){
            scanf("%d%d",&island[i].x, &island[i].y);
            yPos[i] = island[i].y;
        }
        sort(yPos.begin(), yPos.end());
        yPos.erase(unique(yPos.begin(), yPos.end()), yPos.end());
        for(int i=0;i<N;i++){
            int y = lower_bound(yPos.begin(), yPos.end(), island[i].y)-yPos.begin();
            island[i].y = y;
        }
        sort(island, island+N, comp);
        int n = yPos.size();
        vector<int>seg(n*4);
        long long int answer = 0;
        for(int i=0;i<N;i++){
            int y = island[i].y;
            answer += query(seg, 1, 0, n-1, 0, y);
            update(seg, 1, 0, n-1, y);
        }
        cout<<answer<<"\n";
    }
    return 0;
}
