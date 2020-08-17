#include <iostream>

using namespace std;

int Answer;
int score[5005];
int main(int argc, char** argv)
{
	int T, test_case;

	scanf("%d",&T);
	for(test_case = 0; test_case  < T; test_case++)
	{
        int n;
        scanf("%d",&n);
		Answer = 0;

        int a[n+1], b[n+1];
        int similarity = 0;
        for(int i=1;i<=n;i++){
            scanf("%d",&a[i]);
        }
        for(int i=1;i<=n;i++){
            scanf("%d",&b[i]);
            score[i] = score[i-1];
            if(a[i]==b[i]){
                score[i]++;
            }
        }
        //odd
        for(int k=1;k<=n;k++){
            int i=k, j=k;
            int simil = 0;
            while(i>=1 && j<=n){
                if(a[i]==b[j])
                    simil++;
                if(j!=i && a[j]==b[i])
                    simil++;
                Answer = max(Answer, simil+score[i-1]+score[n]-score[j]);
                i--;
                j++;
            }
        }
        //even
        for(int k=1;k<=n;k++){
            int i=k, j=k+1;
            int simil = 0;
            while(i>=1 && j<=n){
                if(a[i]==b[j])
                    simil++;
                if(a[j]==b[i])
                    simil++;
                Answer = max(Answer, simil+score[i-1]+score[n]-score[j]);
                i--;
                j++;
            }
        }
		// Print the answer to standard output(screen).
		cout << "Case #" << test_case+1 << "\n";
		cout << Answer << "\n";
	}
	return 0;
}
