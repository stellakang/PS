#include <iostream>
using namespace std;

int Answer;
int dp[1000005];
int main(int argc, char** argv)
{
	int T, test_case;
	// freopen("input.txt", "r", stdin);
	dp[1] = 0;
	dp[2] = 1;
	for(int num=2;num<=500000;num++){
	    dp[num*2] = dp[num] + 1;
	    dp[num*2-1] = dp[num] + 2;
	}
	scanf("%d",&T);
	for(test_case = 0; test_case  < T; test_case++)
	{

		Answer = 0;
		int N1, N2;
		scanf("%d%d",&N1,&N2);
		for(int i=N1;i<=N2;i++){
		    Answer += dp[i];
		}
		// Print the answer to standard output(screen).
		cout << "Case #" << test_case+1 << "\n";
		cout << Answer << "\n";
	}

	return 0;//Your program should return 0 on normal termination.
}
