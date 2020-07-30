# Recursion and Dynamic Programming  

## Recursion  
- 해당 문제를 부분 문제로 만들 수 있는지 확인한다.  

### 1. 접근법  
- 상향식 bottom-up   
  이전에 풀었던 사례를 확장하여 다음 풀이를 찾는다.  

- 하향식 top-down    
  어떻게 하면 N에 대한 문제를 부분 문제로 나눌 수 있을지 생각해 본다.  

- 반반 half-and-half  
  binary search(이진 탐색)이나 merge sort(병합 정렬)이 여기에 해당한다.  
  

### 2. 재귀적 해법 vs 순환적 해법   

- 재귀적 해법(recursive)    
  - 재귀 호출이 한 번 발생할 때마다 스택에 새로운 층을 추가  
  - 깊이가 n이면 메모리 O(n) 사용  
  
- 순환적 해법(iterative)    
  - 코드가 때로는 더 복잡  
  
## Dynamic programming  
- 거의 대부분 '재귀적 알고리즘' & '반복적으로 호출되는 부분문제를 찾아내는 것'  
- 피보나치 수열  
  - 시간 복잡도: O(2^n)  

### 1. Top-down  
- 메모이제이션: 결과를 저장하고 나중에 저장된 값 사용  
- 피보나치 문제 수행시간: O(n)  

### 2. Bottom-up  
- base case를 계산한 후 상향식으로 구현  

  

