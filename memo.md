## 코딩할 때 주의할 점  

- 전체적으로 코드를 구성하는 과정을 거친 후 코딩하자.  

array  
- 인자를 넘길 때, 이차원 배열의 경우 int arr[][3] 이런 식으로 상수의 크기가 할당되어야 가능하다.  
  이렇게 전달하기 힘들 경우에는 최대 크기를 지정할 것  
- int arr[][]의 경우, call by reference  
  struct의 경우, call by value   

자주하는 실수    
- min, max값 설정 시 주의  
  max값도 음수값이 될 수 있다.  
  int의 경우,   
  min: -2^31(0x80000000)    
  max: 2^31-1(0x7fffffff) 

