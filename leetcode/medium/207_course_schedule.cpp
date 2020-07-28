//dfs
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>graph;
        graph.resize(numCourses);
        
        for(auto edge: prerequisites)
            graph[edge[1]].push_back(edge[0]);
        
        vector<int>visit;
        visit.resize(numCourses,0);
        for(int i=0;i<numCourses;i++){
            if(visit[i]==0 && isCycle(i, visit, graph))
                return false;
        }
        return true;
    }
    bool isCycle(int n, vector<int>&visit, vector<vector<int>>&graph){
        visit[n]=1;
        for(int neighbor: graph[n]){
            if(visit[neighbor]==1)
                return true;
            if(visit[neighbor]==0 && isCycle(neighbor, visit, graph))
                return true;    
        }
        visit[n]=2;
        return false;
    }
};

//bfs
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int num=0;
        queue<int>qu;
        vector<int>indegree;
        vector<vector<int>>graph;
        
        indegree.resize(numCourses,0);
        graph.resize(numCourses);
        
        for(auto edge: prerequisites){
            graph[edge[1]].push_back(edge[0]);
            indegree[edge[0]]++;
        }
        for(int i=0;i<numCourses;i++){
            if(indegree[i]==0)
                qu.push(i);
        }
        while(!qu.empty()){
            int course = qu.front();
            qu.pop();
            num++;
            for(int neighbor:graph[course]){
                if(--indegree[neighbor]==0)
                    qu.push(neighbor);
            }
        }
        if(num==numCourses)
            return true;
        return false;
    }
    
};
