# 비트 조작  

비트는 컴퓨터에서 사용되는 최소 단위로 0, 1 값을 가진다.  
비트 마스크는 이러한 비트를 활용하는 것  

## 비트 연산  
### And 연산  
- 두 비트가 모두 1일 때, 1을 반환  
- 1011 & 1111 = 1010  

### Or 연산  
- 두 비트가 모두 1이거나 하나라도 1일 때, 1을 반환  
- 1011 | 1111 = 1111  

### Xor 연산  
- 두 비트가 서로 다르면 1을 반환  
- 1011 ^ 1111 = 0100  

### Not 연산  
- 비트 값을 바꾸어 반환  
- ~1011 = 0100  

### Shift 연산  
- `<< i` : 왼쪽으로 i번 만큼 비트를 옮긴다.  
- `>> i` : 오른쪽으로 i번 만큼 비트를 옮긴다.  

## 기본적인 비트 조작  
### 1. 비트값 확인  
```c++
bool getBit(int num, int i){
  return ((num & (1<<i) != 0);
}
```
### 2. 비트값 채워넣기  
i번째의(0베이스) 비트값을 1로 바꾼다.  
```c++
int setBit(int num, int i){
    return num | (1<<i);
}
```

### 3. 비트값 삭제하기  
i번째 비트값만 0으로 바꾼다.  
```c++
int clearBit(int num, int i){
    int mask = ~(1 << i);
    return num & mask;
}
```
최상위 비트에서 i번째 비트까지 모두 삭제한다.  
```c++
int clearBitsMSBthroughI(int num, int i){
    int mask = (1<<i) - 1;
    return num & mask;
}
```
i번째 비트에서 0번째 비트까지 모두 삭제한다.  
```c++
int clearBitsIthrough0(int num, int i){
    int mask = (-1 << (i+1));
    return num & mask;
}
```
### 4. 비트값 바꾸기  
i번째 비트값을 v로 바꾼다.  
```c++
int updateBit(int num, int i, bool bitIs1){
    int value = bitIs1? 1 : 0;
    int mask = ~(1 << i);
    return (num & mask) | (value << i);
}
```
