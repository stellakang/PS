#include <iostream>
#define TREE_SIZE 90000
using namespace std;

struct tree{
    int x,y,age;
};

int N,numTrees=0;
int nutriment[11][11];
int trees[11][11][TREE_SIZE];
int frontIndx[11][11];
int rearIndx[11][11];
int A[11][11];

void springWinter();
void summerFall();

int main(){
    int M,K;
    cin>>N>>M>>K;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin>>A[i][j];
            nutriment[i][j]=5;
        }
    }
    numTrees += M;
    while(M--){
        int x,y,z;
        cin>>x>>y>>z;
        trees[x-1][y-1][0] = z;
        rearIndx[x-1][y-1] = 1;
    }
    while(K--){
        springWinter();
        summerFall();
    }
    cout<<numTrees<<"\n";
    return 0;
}
void springWinter(){
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            int front = frontIndx[i][j];
            int rear = rearIndx[i][j];
            int nutri = nutriment[i][j];
            int dead = 0;
            for(int t=rear-1;t>=front;t--){
                int age = trees[i][j][t];
                if(nutri-age>=0){
                    nutri-=age;
                    trees[i][j][t]++;
                }
                else{
                    dead += age/2;
                    frontIndx[i][j]++;
                    numTrees--;
                }
            }
            nutriment[i][j] = nutri + dead + A[i][j];
        }
    }
}
void summerFall(){
    int dx[8]={-1,-1,0,1,1,1,0,-1};
    int dy[8]={0,1,1,1,0,-1,-1,-1};
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            int front = frontIndx[i][j];
            int rear = rearIndx[i][j];
            for(int t=front;t<rear;t++){
                int age = trees[i][j][t];
                if(age%5==0){
                    for(int k=0;k<8;k++){
                        int xi = i+dx[k];
                        int yi = j+dy[k];
                        if(xi<0 || xi>=N || yi<0 || yi>=N)continue;
                        trees[xi][yi][rearIndx[xi][yi]++] = 1;
                        numTrees++;
                    }
                }
            }
        }
    }
}
