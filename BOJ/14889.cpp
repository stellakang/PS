#include <iostream>
using namespace std;

int sum;
int minDiff=0x7fffffff;
int S[25][25];
bool team1[25];
int abs(int a, int b);
void makeTeam(int N, int teamNum, int cur, int power1, int power2);
int main(){
    int N;
    cin>>N;
    
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            cin>>S[i][j];
            sum+=S[i][j];
        }
    }
    makeTeam(N,0,0,0,sum);
    cout<<minDiff<<"\n";
    return 0;
}
void makeTeam(int N, int teamNum, int cur, int power1, int power2){
    for(int i=1;i<=N;i++){
        if(team1[i])
            power1 += S[i][cur]+S[cur][i];
        else
            power2 -= S[i][cur]+S[cur][i];
    }
    if(teamNum==N/2){
        int diff = abs(power1, power2);
        if(minDiff>diff)
            minDiff = diff;
        return;
    }
    for(int i=cur+1;i<=N/2+teamNum+1;i++){
        team1[i]=true;
        makeTeam(N, teamNum+1, i, power1, power2);
        team1[i]=false;
    }
}
int abs(int a, int b){
   if(a>b)
       return a-b;
    return b-a;
}

