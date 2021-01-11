#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <string>
using namespace std;
#define MAX_SIZE 200

void insertion_sort(int list[], int n){
  for(int i=1;i<n;i++){
      int key = list[i];
      int j;
      for(j=i-1;j>=0 && list[j]>key;j--){
          list[j+1] = list[j];
      }
      list[j+1] = key;
  }
}

int main(){
    int n;
    cin>>n;
    int before[n];
    for(int i=0;i<n;i++){
        cin>>before[i];
    }
    insertion_sort(before, n);
    for(int i=0;i<n;i++){
        cout<<before[i]<<" ";
    }
    return 0;
}
