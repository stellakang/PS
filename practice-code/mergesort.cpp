#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <string>
using namespace std;
#define MAX_SIZE 200
int sorted[MAX_SIZE];
void merge(int list[], int left, int mid, int right){
    int i,j,k,l;
    i = left;
    j = mid+1;
    k = left;

    while(i<=mid && j<=right){
        if(list[i]<=list[j]){
            sorted[k++] = list[i++];
        }
        else{
            sorted[k++] = list[j++];
        }
    }

    for(l=j;l<=right;l++)
        sorted[k++] = list[l];
    for(l=i;l<=mid;l++)
        sorted[k++] = list[l];
    
    for(l=left;l<=right;l++){
        list[l] = sorted[l];
    }
}

void merge_sort(int list[], int left, int right){
    if(left<right){
        int mid = (left+right)/2;
        merge_sort(list, left, mid);
        merge_sort(list, mid+1, right);
        merge(list, left, mid, right);
    }
}

int main(){
    int n;
    cin>>n;
    int before[n];
    for(int i=0;i<n;i++){
        cin>>before[i];
    }
    merge_sort(before, 0, n-1);
    for(int i=0;i<n;i++){
        cout<<sorted[i]<<" ";
    }
    return 0;
}
