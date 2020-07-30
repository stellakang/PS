class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> indegree;
        indegree.resize(numCourses,0);
        
        vector<vector<int>>graph;
        graph.resize(numCourses);
        for(vector<int>pairs:prerequisites){
            graph[pairs[1]].push_back(pairs[0]);
            indegree[pairs[0]]++;
        }
        
        queue<int>qu;
        for(int i=0;i<numCourses;i++){
            if(indegree[i]==0)
                qu.push(i);
        }
        
        int cnt=0;
        vector<int>ordering;
        while(!qu.empty()){
            cnt++;
            int course = qu.front();
            qu.pop();
            ordering.push_back(course);
            
            for(int nextCourse:graph[course]){
                if(--indegree[nextCourse]==0)
                    qu.push(nextCourse);
            }
        }
        
        if(cnt==numCourses)
            return ordering;
        else
            return {};
    }
};
