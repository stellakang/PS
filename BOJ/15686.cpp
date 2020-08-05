#include <iostream>
using namespace std;

struct pos{
    int x,y;
};

int M;
int minDistance=0x7fffffff;
pos chicken[14];
pos house[105];
bool check[14];
int numChicken=0;//the number of chicken house
int numHouse=0;

int abs(int a, int b);
int calculateDistance();
void chooseChickenHouse(int prevIndx,int num);

int main(){
    int N;
    cin>>N>>M;
    int city[55][55];
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin>>city[i][j];
            if(city[i][j] == 2)
                chicken[numChicken++] = {i,j};
            else if(city[i][j] == 1)
                house[numHouse++] = {i,j};
        }
    }
    chooseChickenHouse(-1, 0);
    cout<< minDistance << "\n";
    return 0;
}
void chooseChickenHouse(int prevIndx, int num){
    if(num==M){
        int distance = calculateDistance();
        if(distance < minDistance)
            minDistance = distance;
        return;
    }
    for(int i = prevIndx+1; i < numChicken; i++){
        check[i] = true;
        chooseChickenHouse(i, num+1);
        check[i] = false;
    }
}
int calculateDistance(){
    int sum = 0;
    for(int i = 0; i < numHouse; i++){
        int minD = 0x7fffffff;
        for(int j = 0; j < numChicken; j++){
            if(check[j] == false)continue;
            int d = abs(house[i].x, chicken[j].x)+abs(house[i].y, chicken[j].y);
            if(minD > d)
                minD = d;
        }
        sum += minD;
    }
    return sum;
}
int abs(int a, int b){
    if(a > b)
        return a - b;
    else
        return b - a;
}

