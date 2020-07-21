# Graph

## 정의  
: node와 그 node를 연결하는 edge를 하나로 모아 놓은 것  


## 용어    

### 1. 방향성  
- directed graph: 방향성이 있는 그래프  
- undirected graph: 방향성이 없는 그래프    

### 2. 연결(Connected)   
- connected graph: 임의의 두 node 사이에 경로가 존재하는 경우(1개의 connected component를 가진다.)    
- strongly connected graph: 임의의 두 노드 a,b에 대해서 a에서 b로 가는 경로, b에서 a로 가는 경로가 존재하는 경우    
- connected component: 노드와 에지가 서로 겹치지 않는 subgraph를 component라고 하고 component내 모든 노드쌍에 대해 경로가 존재하는 경우 connected component라고 한다.   

### 3. 완전 그래프(complete graph)   
- complete graph: 모든 node들이 edge로 연결되어 있어 edge의 수가 최대인 그래프   
- clique: undirected graph에서 각 node가 다른 모든 node에 인접해있는 부분 그래프   

### 4. degree  
- indegree: 해당 node로 들어오는 edge수  
- outdegree: 해당 node에서 나가는 edge수  

## 그래프의 표현  


## 그래프의 탐색  

