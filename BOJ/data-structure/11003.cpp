#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;

int main() {
	int N,L;
	scanf("%d%d",&N,&L);

	deque<pair<int,int> >dq;
	for(int i=0;i<N;i++){
		int number;
		scanf("%d",&number);
		while(!dq.empty() && dq.front().second<i-L+1){
			dq.pop_front();
		}
		while(!dq.empty() && dq.back().first>number){
			dq.pop_back();
		}
		dq.push_back(make_pair(number,i));
		cout<<dq.front().first<<"\n";
	}
	return 0;
}
