#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;
int main() {
	int n;
	scanf("%d",&n);
	int num[n];
	for(int i=0;i<n;i++){
		scanf("%d",&num[i]);
	}
	int lis[n];
	int tr[n];
	int pos[n];
	int cnt = 0;
	for(int i=0;i<n;i++){
		int indx = lower_bound(lis,lis+cnt,num[i])-lis;
		lis[indx] = num[i];
		pos[indx] = i;
		if(indx==0){
			tr[i] = -1;
		}
		else{
			tr[i] = pos[indx-1];
		}
		if(indx==cnt){
			cnt++;
		}
	}
	stack<int>st;
	st.push(pos[cnt-1]);
	while(tr[st.top()]!=-1){
		st.push(tr[st.top()]);
	}
	cout<<cnt<<"\n";
	while(!st.empty()){
		cout<<num[st.top()]<<" ";
		st.pop();
	}
	cout<<"\n";
	return 0;
}
