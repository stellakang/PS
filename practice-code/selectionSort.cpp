#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <string>
using namespace std;
#define MAX_SIZE 200

void selection_sort(int list[], int n){
  for(int i=0;i<n-1;i++){
    int indxMin = i;
    for(int j=i+1;j<n;j++){
        if(list[j] < list[indxMin]){
            indxMin = j;
        }
    }
    int tmp = list[indxMin];
    list[indxMin] = list[i];
    list[i] = tmp;
  }
}

int main(){
    int n;
    cin>>n;
    int before[n];
    for(int i=0;i<n;i++){
        cin>>before[i];
    }
    selection_sort(before, n);
    for(int i=0;i<n;i++){
        cout<<before[i]<<" ";
    }
    return 0;
}
