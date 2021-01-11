#include <iostream> 
using namespace std;
#define parent(x) (x-1)/2 

void heap(int data[], int num){ 
    for(int i=1; i<num; i++){ 
        int child = i; 
        while(child > 0){ 
            int root = parent(child); 
            if(data[root] < data[child]){ 
                int temp = data[root]; 
                data[root] = data[child]; 
                data[child] = temp; 
            } 
            child = root; 
        } 
    } 
} 

int main(void){ 
    int n;
    cin>>n;
    int data[n];
    for(int i=0;i<n;i++){
        cin>>data[i];
    }
    heap(data, n);  
    for(int i=n-1; i>=0; i--){ 
        int temp = data[i]; 
        data[i] = data[0]; 
        data[0] = temp; 
        heap(data, i); 
    } 
    // 결과 출력 
    for(int i=0; i<n; i++){ 
        printf("%d ", data[i]); 
    } 
    return 0; 
}
