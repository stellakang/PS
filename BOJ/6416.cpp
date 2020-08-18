#include <iostream>
#include <vector>
#include <unordered_map>
#define um unordered_map
using namespace std;
void printTree(int testCase);
void printNotATree(int testCase);
bool dfs(int node, um<int, bool>&visit, um<int, vector<int> >&graph);
int main(){
    // input
    int testCase = 1;
    while(true){
        int u, v;
        um<int, bool>visit;
        um<int,int>indegree;
        um<int, vector<int> >graph;
        while(true){
            scanf("%d%d",&u, &v);
            if(u==0 && v==0)break;//input end
            if(u==-1 && v==-1)break;
            visit[u] = false;
            visit[v] = false;
            // v indegree ++
            indegree[v]++;
            if(indegree.find(u)==indegree.end()){
                indegree[u] = 0;
            }
            // add u->v edge in the graph
            graph[u].push_back(v);
        }
        if(u==-1 && v==-1)break;//exit
        // check whether graph or not
        int cnt = 0;
        int notRoot = 0;
        int root = -1;
        for(pair<int, int>pi : indegree){
            if(pi.second==0){
                cnt++;
                root = pi.first;
            }
            else{
                notRoot ++;
            }
        }
        if(cnt==1 || (notRoot==0 && cnt==0)){
            //dfs check(cycle check)
            if(dfs(root, visit, graph)){
                //check if there is no visit area
                for(pair<int,bool>pi : visit){
                    if(pi.second==false){
                        // not a tree;
                        printNotATree(testCase);
                        return 0;
                    }
                }
                // a tree
                printTree(testCase);
            }
            else{
                // not a tree
                printNotATree(testCase);
            } 
        }
        else{
            // not a tree
            printNotATree(testCase);
        }
        testCase++;
    }
    return 0;
}
bool dfs(int node, um<int, bool>&visit, um<int, vector<int> >&graph){
    visit[node] = true;
    vector<int> to = graph[node];
    for(int i=0;i<to.size();i++){
        if(visit[to[i]]){
            return false;
        }
        visit[to[i]] = true;
        if(!dfs(to[i], visit, graph)){
            return false;
        }
    }
    return true;
}
void printTree(int testCase){
    cout<<"Case "<<testCase<<" is a tree.\n";
}
void printNotATree(int testCase){
    cout<<"Case "<<testCase<<" is not a tree.\n";
}
