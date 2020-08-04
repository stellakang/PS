#include <iostream>
using namespace std;

struct pos{
    int x,y;
};
int N,M,cctvNum;
int minArea=0x7fffffff;
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
void process(pos cctv[], int num, int office[][10], int area);
int observe(int office[][10], bool dir[], pos c);
void copyArray(int dest[][10], int src[][10]);
int main(){
    cin>>N>>M;
    int office[10][10];
    pos cctv[8];
    int area=0;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            cin>>office[i][j];
            if(office[i][j]>=1 && office[i][j]<=5){
                cctv[cctvNum++]={i,j};
            }
            else if(office[i][j]!=6)
                area++;
        }
    }
    process(cctv, 0, office, area);
    cout<<minArea<<"\n";
    return 0;
}

void process(pos cctv[], int num, int office[][10], int area){
    if(num==cctvNum){
        if(minArea>area)
            minArea = area;
        return;
    }
    pos c = cctv[num];
    int number = office[c.x][c.y];
    if(number==1){
        for(int i=0;i<4;i++){
            int officeCopy[10][10];
            copyArray(officeCopy, office);
            bool dir[4]={false,false,false,false};
            dir[i]=true;
            int observed = observe(officeCopy, dir, c);
            process(cctv, num+1, officeCopy, area-observed);
        }
    }
    else if(number==2){
        for(int i=0;i<2;i++){
            int officeCopy[10][10];
            copyArray(officeCopy, office);
            bool dir[4]={true,true,true,true};
            dir[i]=false;
            dir[(i+2)%4]=false;
            int observed = observe(officeCopy, dir, c);
            process(cctv, num+1, officeCopy, area-observed);
        }
    }
    else if(number==3){
        for(int i=0;i<4;i++){
            int officeCopy[10][10];
            copyArray(officeCopy, office);
            bool dir[4]={true,true,true,true};
            dir[i]=false;
            dir[(i+1)%4]=false;
            int observed = observe(officeCopy, dir, c);
            process(cctv, num+1, officeCopy, area-observed);
        }
    }
    else if(number==4){
        for(int i=0;i<4;i++){
            int officeCopy[10][10];
            copyArray(officeCopy, office);
            bool dir[4]={true,true,true,true};
            dir[i]=false;
            int observed = observe(officeCopy, dir, c);
            process(cctv, num+1, officeCopy, area-observed);
        }
    }
    else{
        //number=5
        int officeCopy[10][10];
        copyArray(officeCopy, office);
        bool dir[4]={true,true,true,true};
        int observed = observe(officeCopy, dir, c);
        process(cctv, num+1, officeCopy, area-observed);
    }
}
int observe(int office[][10], bool dir[], pos c){
    int observed=0;
    for(int i=0;i<4;i++){
        if(!dir[i])continue;
        int x = c.x;
        int y = c.y;
        while(true){
            x+=dx[i];
            y+=dy[i];
            if(x<0||x>=N||y<0||y>=M)break;
            if(office[x][y]==6)break;
            if(office[x][y]==0){
                office[x][y]=-1;
                observed++;
            }
        }
    }
    return observed;
}
void copyArray(int dest[][10], int src[][10]){
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            dest[i][j] = src[i][j];
        }
    }
}
