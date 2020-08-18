# 정렬 알고리즘  
* 장단점 정리하기  
## bubble sort 버블 정렬  
배열의 첫 원소부터 순차적으로 진행하며, 현재 원소가 그다음 원소의 값보다 크면 두 원소를 바꾸는 작업을 반복   
time complexity: Best O(N^2) Avg O(N^2) Worst O(N^2)   
space complexity: O(1)  
```c++
void bubble_sort(int list[], int n){
  int i, j, temp;

  for(i=n-1; i>0; i--){
    // 0 ~ (i-1)까지 반복
    for(j=0; j<i; j++){
      // j번째와 j+1번째의 요소가 크기 순이 아니면 교환
      if(list[j]<list[j+1]){
        temp = list[j];
        list[j] = list[j+1];
        list[j+1] = temp;
      }
    }
  }
}
```

## selection sort 선택 정렬   
가장 작은 원소를 배열 맨 앞으로 보내고 그 다음으로 작은 원소를 앞으로 보내는 과정을 반복한다.   
time complexity: Best O(N^2) Avg O(N^2) Worst O(N^2)    
space complexity: O(1)   
```c++
void selection_sort(int list[], int n){
  int i, j, least;

  // 마지막 숫자는 자동으로 정렬되기 때문에 (숫자 개수-1) 만큼 반복
  for(i=0; i<n-1; i++){
    least = i;
    // 최솟값 탐색  
    for(j=i+1; j<n; j++){
      if(list[j]<list[least])
        least = j;
    }
    // 최솟값이 자기 자신이면 자료 이동을 하지 않는다.
    if(i != least){
        swap(list[i], list[least]);
    }
  }
}
```

## merge sort 병합 정렬  
배열을 절반씩 나누어 각각을 정렬한 다음 다시 합하여 정렬하는 방법  
time complexity: Best O(NlogN) Avg O(NlogN) Worst O(NlogN)    
space complexity: 상황에 따라 다름  
```c++
int sorted[MAX_SIZE];
void merge(int list[], int left, int mid, int right){
  int i, j, k, l;
  i = left;
  j = mid+1;
  k = left;
  //분할 정렬된 list의 합병  
  while(i<=mid && j<=right){
    if(list[i]<=list[j])
      sorted[k++] = list[i++];
    else
      sorted[k++] = list[j++];
  }
  // 남아 있는 값들을 일괄 복사
  for(l=j; l<=right; l++)
    sorted[k++] = list[l];
  for(l=i; l<=mid; l++)
    sorted[k++] = list[l];
  // 배열 sorted[](임시 배열)의 리스트를 배열 list[]로 재복사
  for(l=left; l<=right; l++){
    list[l] = sorted[l];
  }
}
// 합병 정렬
void merge_sort(int list[], int left, int right){
  if(left<right){
    int mid = (left+right)/2 // 중간 위치를 계산하여 리스트를 균등 분할 -분할(Divide)
    merge_sort(list, left, mid); // 앞쪽 부분 리스트 정렬 -정복(Conquer)
    merge_sort(list, mid+1, right); // 뒤쪽 부분 리스트 정렬 -정복(Conquer)
    merge(list, left, mid, right); // 정렬된 2개의 부분 배열을 합병하는 과정 -결합(Combine)
  }
}
```

## insertion sort 삽입 정렬  
time complexity: Best O(N) Avg O(N^2) Worst O(N^2)    
space complexity: O(1)  
```c++
void insertion_sort(int list[], int n){
  int i, j, key;

  // 인텍스 0은 이미 정렬된 것으로 볼 수 있다.
  for(i=1; i<n; i++){
    key = list[i];
    // 현재 i-1까지 정렬된 상태  
    // key가 들어갈 위치를 찾는다.  
    for(j=i-1; j>=0 && list[j]>key; j--){
      list[j+1] = list[j];  
    }
    list[j+1] = key;
  }
}
```
