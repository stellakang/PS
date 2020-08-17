#include <iostream>

using namespace std;

int Answer;
bool prime[30005];

void choosePrime(){
    for(int i=2;i<=30000;i++){
        prime[i] = true;
    }
    for(int i=2;i<=30000;i++){
        if(prime[i]){
            for(int j=i*2;j<=30000;j+=i){
                prime[j] = false;
            }
        }
    }
}
int getScore(int digit[], int indx){
    int maxScore = 0;
    for(int i=0;i<indx;i++){
        int number = 0;
        for(int j=indx-1;j>=0;j--){
            if(i==j)continue;
            number = number*10 + digit[j];
        }
        if(prime[number]){
            int digit2[5];
            int cnt = 0;
            for(int j=0;j<indx;j++){
                if(j==i)continue;
                digit2[cnt++] = digit[j];
            }
            maxScore = max(maxScore, 1+getScore(digit2, cnt));
        }
    }
    return maxScore;
}
int main(int argc, char** argv)
{
    choosePrime();
	int T, test_case;
	cin >> T;
	for(test_case = 0; test_case  < T; test_case++)
	{
        int num[2],score[2];
        scanf("%d%d",&num[0],&num[1]);
        
        for(int i=0;i<2;i++){
            if(prime[num[i]]==false){
                score[i] = 0;
                continue;
            }
            int digit[5];
            int indx = 0;
            int number = num[i];
            while(number>0){
                digit[indx++] = number%10;
                number /= 10;
            }
            score[i] = 1 + getScore(digit, indx);
        }
		if(score[0]>score[1])
		    Answer = 1;
		else if(score[0]==score[1])
		    Answer = 3;
		else
		    Answer = 2;
		
		cout << "Case #" << test_case+1 << "\n";
		cout << Answer << "\n";
	}

	return 0;//Your program should return 0 on normal termination.
}
