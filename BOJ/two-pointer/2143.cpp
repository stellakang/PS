#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int a[1005];
int b[1005];
vector<int>sumA;
vector<int>sumB;

int main() {
	int T,n,m;
	cin>>T>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	cin>>m;
	for(int i=0;i<m;i++){
		cin>>b[i];
	}
	for(int i=0;i<n;i++){
		int sum = 0;
		for(int j=i;j<n;j++){
			sum += a[j];
			sumA.push_back(sum);
		}
	}
	for(int i=0;i<m;i++){
		int sum = 0;
		for(int j=i;j<m;j++){
			sum += b[j];
			sumB.push_back(sum);
		}
	}
	sort(sumA.begin(), sumA.end());
	sort(sumB.begin(), sumB.end());
	int aIndx = 0, bIndx = sumB.size()-1;
	long long cnt = 0;
	while(aIndx<sumA.size() && bIndx>=0){
		int sum = sumA[aIndx] + sumB[bIndx];
		if(sum<T){
			aIndx ++;
		}
		else if(sum>T){
			bIndx--;
		}
		else{
			int aCnt = 0;
			while(aIndx+aCnt<sumA.size() && sumA[aIndx] == sumA[aIndx+aCnt]){
				aCnt++;
			}
			int bCnt = 0;
			while(bIndx-bCnt>=0 && sumB[bIndx] == sumB[bIndx-bCnt]){
				bCnt++;
			}
			aIndx += aCnt;
			bIndx -= bCnt;
			cnt += (long long)aCnt * (long long)bCnt;
		}
	}
	cout<<cnt<<"\n";
	return 0;
}

