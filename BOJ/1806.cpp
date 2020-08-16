#include <iostream>
using namespace std;

int N,S;
int num[100005];
int main() {
	cin>>N>>S;
	for(int i=0;i<N;i++){
		cin>>num[i];
	}
	int minLen=N+1, sum = num[0];
	int left = 0, right = 0;
	while(left<=right){
		if(sum<S){
			if(right+1<N){
				right ++;
				sum += num[right];
			}
			else{
				break;
			}
		}
		else{
			minLen = min(minLen, right-left+1);
			sum -= num[left];
			left++;
		}
	}
	if(minLen>N){
		cout<<"0\n";
	}
	else{
		cout<<minLen<<"\n";
	}
	return 0;
}

