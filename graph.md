# Graph

## 정의  
: vertex와 그 vertex를 연결하는 edge를 하나로 모아 놓은 것  


## 용어    
### 0. 경로(path)  
- 그래프 상에 edge가 있는 곳을 움직이는 자취  
- simple path: 같은 vertex가 없는 path   

### 1. 방향성  
- directed graph: 방향성이 있는 그래프  
- undirected graph: 방향성이 없는 그래프    

### 2. 연결(Connected)   
- connected graph: 임의의 두 vertex 사이에 경로가 존재하는 경우(1개의 connected component를 가진다.)    
- strongly connected graph: 임의의 두 vertex a,b에 대해서 a에서 b로 가는 경로, b에서 a로 가는 경로가 존재하는 경우    
- connected component: vertex와 edge가 서로 겹치지 않는 subgraph를 component라고 하고 component내 모든 노드쌍에 대해 경로가 존재하는 경우 connected component라고 한다.   

### 3. 완전 그래프(complete graph)   
- complete graph: 모든 vertex들이 edge로 연결되어 있어 edge의 수가 최대인 그래프   
- clique: undirected graph에서 각 vertex가 다른 모든 vertex에 인접해있는 부분 그래프   

### 4. degree  
- indegree: 해당 vertex로 들어오는 edge수  
- outdegree: 해당 vertex에서 나가는 edge수  

### 5. bipartite graph  
- 정점들을 두 개의 서로 다른 집합 V1, V2(=V-V1)으로 나눌 수 있는 undirected graph    

### 6. cycle  
- cyclic graph: cycle이 존재하는 그래프    
- acyclic graph: cycle이 존재하지 않는 그래프, 비순환 그래프  

### 7. vertex/edge-cut  
- vertex cut: 그래프에서 특정 노드를 제거해 부분 그래프로 나누는 것  
- edge cut: 그래프에서 특정 에지를 제거해 부분 그래프로 나누는 것  

## 그래프의 표현  
### 1. 인접리스트   
```
  class Graph{
    public Node[] nodes;
  }
  class Node{
    public String name;
    public Node[] children;
  }
```
예)  
연결되어 있는 부분만 연결해주면 된다.  
0: 1  
1: 2  
2: 0, 3  
3: 2  
4: 6  
5: 4  
6: 5  

### 2. 인접행렬   
- NxN 행렬, matrix[i][j]=1 는 i에서 j로의 간선이 있다는 뜻이다.  
- 무방향 그래프를 인접 행렬로 표현한다면 이 행렬은 대칭행렬이 된다.  
- 모든 노드를 순회해야 한다는 문제.  

## 그래프의 탐색  

### 1. BFS  
- breadth first search: 너비 우선 탐색    
- 루트 노드에서 시작해서 인접한 노드를 먼저 탐색하는 방법이다.  
- queue 사용  
- 시간 복잡도: 인접리스트(O(V+E)), 인접행렬(O(V^2))  

### 2. DFS  
- depth first search: 깊이 우선 탐색  
- stack 사용  
- 시간복잡도: 인접리스트(O(V+E)), 인접행렬(O(V^2))  

## 기타 알고리즘  

### 1. 위상정렬  
- 방향 그래프에서 노드의 리스트에 순서를 매기는 방법  
- 그래프에 사이클이 존재하거나 방향 그래프가 아니라면 위상정렬은 존재하지 않는다.  
- 알고리즘  
  - indegree가 0인 모든 노드를 찾은 뒤에 이들을 위상정렬에 추가한다.  
  - 해당 노드의 outbound edge를 제거한다.  
  - 위 과정을 반복한다.  
- 시간복잡도: O(V+E)  
- 코드

### 2. 다익스트라 알고리즘  
- weight가 있는 directed graph에서 두 지점 간의 최단 경로를 찾는 방법  
- priority queue를 사용한다.  
- 알고리즘(s에서 t까지 최단경로)    
  - 처음에 s는 0, s를 제외한 다른 노드는 distance를 INF로 지정한다.     
  - 가장 distance가 작은 노드를 찾아 인접한 노드에 대해 distance가 갱신한다.  
  - 방문한 노드를 제외하고 위 과정을 반복한다.  
  - 모든 노드를 방문하면 시작점부터 모든 노드에 대한 distance가 저장된다.  
- 시간복잡도: O(ElogV)   
- 코드   
