#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <string>
using namespace std;
#define MAX_SIZE 200

void bubble_sort(int list[], int n){
  for(int i=n-1;i>0;i--){
      for(int j=0;j<i;j++){
          if(list[j]>list[j+1]){
              int tmp = list[j];
              list[j] = list[j+1];
              list[j+1] = tmp;
          }
      }
  }
}

int main(){
    int n;
    cin>>n;
    int before[n];
    for(int i=0;i<n;i++){
        cin>>before[i];
    }
    bubble_sort(before, n);
    for(int i=0;i<n;i++){
        cout<<before[i]<<" ";
    }
    return 0;
}
