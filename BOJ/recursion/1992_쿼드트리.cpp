#include <iostream>
#include <string>
using namespace std;

bool grid[65][65];

struct pos{
    int x, y;
};
int countData(pos start, int n){
    int x1 = start.x;
    int y1 = start.y;
    int numOfZero = 0;
    int numOfOne = 0;
    int area = n*n;
    for(int i=x1;i<x1+n;i++){
        for(int j=y1;j<y1+n;j++){
            if(grid[i][j]==true)numOfOne++;
            else numOfZero++;
        }
        if(numOfZero>0 && numOfOne>0)return -1;
    }
    if(area == numOfZero)return 0;
    if(area == numOfOne)return 1;
    return -1;
}

string compact(pos start, int n){
    int ret = countData(start, n);
    if(ret==0)return "0";
    else if(ret==1)return "1";
    int x1 = start.x;
    int y1 = start.y;
    return "("+compact(start, n/2)+compact({x1,y1+n/2}, n/2)
    +compact({x1+n/2,y1}, n/2)+compact({x1+n/2,y1+n/2}, n/2)+")";
}

int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        char str[65];
        scanf("%s",&str);
        for(int j=0;j<n;j++){
            if(str[j]=='1')
                grid[i][j]=true;
        }
    }
    cout<<compact({0,0}, n)<<"\n";

    return 0;
}