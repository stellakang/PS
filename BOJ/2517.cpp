#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

struct runner{
	int rank, indx;
};
bool comp(const runner &a, const runner &b){
	return a.rank>b.rank;
}
bool comp2(const runner &a, const runner &b){
	return a.indx<b.indx;
}
void update(vector<int> &tree, int node, int start, int end, int indx){
	if(!(start<=indx && indx<=end))
		return;
	tree[node]++;
	if(start != end){
		int mid = (start + end)/2;
		update(tree, node*2, start, mid, indx);
		update(tree, node*2+1, mid+1, end, indx);
	}
}
int sum(vector<int>&tree, int node, int start, int end, int left, int right){
	if(left > end || right < start)
		return 0;
	if(left <= start && end <= right)
		return tree[node];
	int mid = (start + end)/2;
	return sum(tree, node*2, start, mid, left, right) + sum(tree, node*2+1, mid+1, end, left, right);
}

int main() {
	int N;
	cin>>N;

	int h = (int)ceil(log2(N));
	int treeSize = 1 << (1+h);
	vector<runner>arr;
	vector<int> segTree(treeSize,0);

	for(int i=0;i<N;i++){
		int rank;
		cin>>rank;
		runner tmp = {rank, i};
		arr.push_back(tmp);
	}
	sort(arr.begin(), arr.end(),comp);
	for(int i=0;i<N;i++){
		update(segTree, 1, 0, N-1, arr[i].indx); 
		arr[i].rank = sum(segTree, 1, 0, N-1, 0, arr[i].indx);
	}
	sort(arr.begin(), arr.end(), comp2);
	for(int i=0;i<N;i++){
		cout<<arr[i].rank<<"\n";
	}
	return 0;
}

