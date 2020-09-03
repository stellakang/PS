#include <iostream>

using namespace std;

int main(int argc, char** argv)
{
	int T, test_case;

	cin >> T;
	for(test_case = 0; test_case  < T; test_case++)
	{
        int n,k;
        cin>>n>>k;
        int x[n+1],y[n+1];
		bool wins[n+1][n+1];
        for(int i=1;i<=n;i++){
            cin>>x[i];
        }
        for(int i=1;i<=n;i++){
            cin>>y[i];
        }
        x[0] = 0;
        y[0] = 0;
        int sumX = 0, sumY = 0;
        int xi = 1, yi = 1;
        int win = 1;
        wins[0][0] = true;
        
        int fx[n+1][n+1], fy[n+1][n+1];
        for(int i=0;i<=n;i++){
            for(int j=0;j<=n;j++){
                fx[i][j] = 0;
                fy[i][j] = 0;
            }
        }
		for(int i=0;i<=n;i++){
            sumX += x[i];
            while(sumX>k){
                sumX -= x[xi++];
            }
            sumY = 0;
            yi = 1;
            for(int j=0;j<=n;j++){
                if(i==0 && j==0)continue;
                sumY += y[j];
                while(sumY>k){
                    sumY -= y[yi++];
                }
                wins[i][j] = false;
                int tmpX = 0, tmpY = 0;
                if(i!=0){
                    tmpX += fx[j][i-1];
                    if(xi!=1)
                        tmpX -= fx[j][xi-2];
                    fx[j][i] = fx[j][i-1];
                }
                if(j!=0){
                    tmpY += fy[i][j-1];
                    if(yi!=1)
                        tmpY -= fy[i][yi-2];
                    fy[i][j] = fy[i][j-1];
                }
                if(tmpX>0 || tmpY>0){
                    wins[i][j] = true;
                    win++; 
                }
                else{
                    fx[j][i]++;
                    fy[i][j]++;
                }
            }
        }
		cout << "Case #" << test_case+1 << "\n";
		cout << win <<" "<<(n+1)*(n+1)-win<<"\n";
	}
	return 0;
}