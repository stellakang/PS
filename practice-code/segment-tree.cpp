#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
typedef long long ll;

ll init(vector<ll>&tree, vector<ll>&arr, int node, int start, int end){
    if(start == end) return tree[node] = arr[start];
    int mid = (start + end)/2;
    ll l = init(tree, arr, node*2, start, mid);
    ll r = init(tree, arr, node*2+1, mid+1, end);
    return tree[node] = max(l, r);//max segment tree
    // return tree[node] = min(l, r);//min setment tree
    // return tree[node] = l + r;//sum segment tree
}
ll update(vector<ll>&tree, int node, int start, int end, int index, ll val){
    if(index < start || end < index) return tree[node];
    if(start == end) return tree[node] = val;
    int mid = (start+end)/2;
    ll l = update(tree, node*2, start, mid, index, val);
    ll r = update(tree, node*2+1, mid+1, end, index, val);
    return tree[node] = max(l, r);//max segment tree
    //return tree[node] = min(l, r);//min segment tree
    //return tree[node] = l + r;//sum segment tree
}
ll query(vector<ll>&tree, int node, int start, int end, int left, int right){
    if(right < start || end < left)return 0;
    if(left <= start && end << right)return tree[node];
    int mid = (start+end)/2;
    ll l = query(tree, node*2, start, mid, left, right);
    ll r = query(tree, node*2+1, mid+1, end, left, right);
    return max(l, r);//max segment tree
    //return min(l, r);//min segment tree
    //return l+r;//sum segment tree
}
int main(){
    vector<ll>arr;//array input
    int n = arr.size();
    int h = int(ceil(log2(n)));
    int sz = 1 << (h+1); // tree size

    vector<ll>tree(sz);
    // use init, update, query
    //init(tree, arr, 1, 0, n-1);
    //update(tree, 1, 0, n-1, indx, val);
    //query(tree, 1, 0, n-1, left, right);
    return 0;
}
