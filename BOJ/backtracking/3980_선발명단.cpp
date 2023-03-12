#include <iostream>

using namespace std;

int maxScore;
int position[12][12];
bool visit[12];

void assignRole(int sumScore, int row){
    if(row==11){
        if(maxScore<sumScore){
            maxScore = sumScore;
            return;
        }
    }
    for(int i=0;i<11;i++){
        if(position[row][i]>0 && visit[i]==false){
            visit[i] = true;
            assignRole(sumScore+position[row][i], row+1);
            visit[i] = false;
        }
    }
}

int main(){
   int C;
   scanf("%d",&C);
   
   for(int i=0;i<C;i++){
       maxScore = 0;
       for(int j=0;j<11;j++){
           visit[j] = false;
       }
       for(int r=0;r<11;r++){
           for(int c=0;c<11;c++){
               scanf("%d",&position[r][c]);
           }
       }
       assignRole(0, 0);
       printf("%d\n",maxScore);
   }

    return 0;
}