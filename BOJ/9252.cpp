#include <iostream>
#include <string.h>
#include <stack>
#include <algorithm>
using namespace std;

int lcs[1005][1005];
int tr[1005][1005];
int main() {
	char str1[1005];
	char str2[1005];
	scanf("%s%s",str1+1,str2+1);

	int sz1 = strlen(str1+1);
	int sz2 = strlen(str2+1);
	for(int i=1;i<=sz1;i++){
		for(int j=1;j<=sz2;j++){
			if(str1[i]==str2[j]){
				lcs[i][j] = lcs[i-1][j-1] + 1;
				tr[i][j] = 2;
			}
			else{
				if(lcs[i][j-1]>lcs[i-1][j]){
					lcs[i][j] = lcs[i][j-1];
					tr[i][j] = 3;
				}
				else{
					lcs[i][j] = lcs[i-1][j];
					tr[i][j] = 1;
				}
			}
		}
	}
	stack<pair<int,int> >st;
	int x = sz1;
	int y = sz2;
	while(x>0 && y>0){
		int t = tr[x][y];
		if(t==1){
			x--;
		}
		else if(t==2){
			st.push(make_pair(x,y));
			x--;
			y--;
		}
		else{
			y--;
		}
	}
	cout<<lcs[sz1][sz2]<<"\n";
	while(!st.empty()){
		int x = st.top().first;
		st.pop();
		cout<<str1[x];
	}
	cout<<"\n";
	return 0;
}
