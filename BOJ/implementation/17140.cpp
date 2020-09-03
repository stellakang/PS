#include <iostream>
using namespace std;

int row = 3;
int col = 3;
int numToCnt[105];
int sameCount[105];
int cntToNum[105][105];
int A[105][105];

void initCount();
void rowOperation();
void colOperation();

int main(){
    //input
    int r,c,k;
    cin>>r>>c>>k;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            cin>>A[i][j];
        }
    }
    int time = 0;
    while(time<=100){
        if(A[r-1][c-1]==k)break;
        if(row>=col){
            rowOperation();
        }
        else{
            colOperation();
        }
        time++;
    }
    if(time>100)
        cout<<"-1\n";
    else
        cout<<time<<"\n";
    return 0;
}
void colOperation(){
    int updateRow = 0;
    for(int i=0;i<col;i++){
        //init count
        initCount();
        for(int j=0;j<row;j++){
            numToCnt[A[j][i]]++;
        }
        for(int j=1;j<=100;j++){
            int cnt = numToCnt[j];
            if(cnt==0)continue;
            // increase cntToNum
            int indx = sameCount[cnt];
            cntToNum[cnt][indx] = j;
            sameCount[cnt]++;
        }
        // fill the array
        int index = 0;
        for(int j=1;j<=100;j++){
            if(sameCount[j]==0)continue;
            if(index==100)
                break;
            for(int k=0;k<sameCount[j];k++){
                A[index++][i] = cntToNum[j][k];
                if(index==100)break;
                A[index++][i] = j;
                if(index==100)break;
            }
        }
        if(updateRow<index)
            updateRow = index;
        for(int j=index;j<100;j++){
            A[j][i] = 0;
        }
    }
    //update Row
    row = updateRow;
}
void rowOperation(){
    int updateCol = 0;
    for(int i=0;i<row;i++){
        initCount();
        for(int j=0;j<col;j++){
            numToCnt[A[i][j]]++;
        }
        //count -> num
        for(int j=1;j<=100;j++){
            int cnt = numToCnt[j];
            if(cnt==0)continue;
            // increase cntToNum
            int indx = sameCount[cnt];
            cntToNum[cnt][indx] = j;
            sameCount[cnt]++;
        }
        // fill the array
        int index = 0;
        for(int j=1;j<=100;j++){
            if(sameCount[j]==0)continue;
            if(index==100)
                break;
            for(int k=0;k<sameCount[j];k++){
                A[i][index++] = cntToNum[j][k];
                if(index==100)break;
                A[i][index++] = j;
                if(index==100)break;
            }
        }
        if(updateCol<index)
            updateCol= index;
        for(int j=index;j<100;j++){
            A[i][j] = 0;
        }
    }
    //update column
    col = updateCol;
}
void initCount(){
    for(int i=0;i<=100;i++){
        numToCnt[i] = 0;
        for(int j=0;j<sameCount[i];j++){
            cntToNum[i][j] = 0;
        }
        sameCount[i] = 0;
    }
}
