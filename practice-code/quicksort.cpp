#include <iostream> 
using namespace std;
void quick_sort(int data[], int start, int end){ 
    if(start >= end)return;

    int pivot = start; 
    int i = pivot + 1; 
    int j = end; 
    int temp; 
    while(i <= j){ 
        while(i<=end && data[i]<=data[pivot])
            i++;
        while(j>start && data[j]>=data[pivot])
            j--;
        if(i>j){
            int tmp = data[pivot];
            data[pivot] = data[j];
            data[j] = tmp;
        }
        else{
            int tmp = data[j];
            data[j] = data[i];
            data[i] = tmp;
        }
    } 
    quick_sort(data, start, j-1);
    quick_sort(data, j+1, end);
} 
int main(){ 
    int n;
    cin>>n;
    int data[n]; 
    for(int i=0;i<n;i++){
        cin>>data[i];
    }
    quick_sort(data, 0, n-1); 
    // 결과 확인 
    for(int i=0; i<n; i++){ 
        printf("%d ", data[i]); 
    } 
    return 0; 
}
