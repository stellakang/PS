#include <iostream>
#include <stdio.h>
using namespace std;

int N,k,m;
int Answer;
int line[2005][2];
int minCut[1505][1505];
void init(){
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            minCut[i][j] = 0x7fffffff;
        }
        minCut[i][i] = 0;
    } 
}
void findPath(){
    int tmp[N+1];
    for(int i=1;i<=k;i++){
        int a = line[i-1][0];
        int b = line[i-1][1];
        for(int j=1;j<=N;j++){
            tmp[j] = minCut[j][b];
            if(minCut[j][a]!=0x7fffffff){
                if(minCut[j][b]!=0x7fffffff){
                    tmp[j] = min(minCut[j][b]+1, minCut[j][a]);//minCut[j][b]
                }
                else{
                    tmp[j] = minCut[j][a];
                }
            }
            else if(minCut[j][b]!=0x7fffffff){
                tmp[j] = minCut[j][b]+1;
            }
        }
        for(int j=1;j<=N;j++){
            if(minCut[j][b]!=0x7fffffff){
                if(minCut[j][a]!=0x7fffffff){
                    minCut[j][a] = min(minCut[j][a]+1, minCut[j][b]);
                }
                else{
                    minCut[j][a] = minCut[j][b];
                }
            }
            else if(minCut[j][a]!=0x7fffffff){
                minCut[j][a] = minCut[j][a]+1;
            }
            minCut[j][b] = tmp[j];
        }
    }
}
int main(int argc, char** argv)
{
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int T, test_case;
	scanf("%d",&T);
	for(test_case = 0; test_case  < T; test_case++)
	{
        scanf("%d%d%d",&N,&k,&m);
        init();
        for(int i=0;i<k;i++){
            scanf("%d%d",&line[i][0],&line[i][1]);
        }
        Answer = 0;
        findPath();
        while(m--){
            int a,b;
            scanf("%d%d",&a,&b);
            if(minCut[a][b] == 0x7fffffff){
                Answer --;
            }
            else{
                Answer += minCut[a][b];
            }
        }
        printf("Case #%d\n%d\n",test_case+1, Answer);
	}
	return 0;
}