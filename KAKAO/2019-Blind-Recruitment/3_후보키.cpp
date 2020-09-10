#include <string>
#include <vector>

using namespace std;

bool keys[520];
bool isInclude(int numKeys, int small, int big){
    for(int i=0;i<numKeys;i++){
        int num = 1<<i;
        if((small&num)>0 && (big&num)==0)return false;
    }
    return true;
}
int solution(vector<vector<string>> relation) {
    int len = relation.size();
    int numKeys = relation[0].size();
    int answer = 0;
    for(int i=1;i<=((1<<numKeys)-1);i++){
        bool existSubset = false;
        for(int j=1;j<i;j++){
            if(keys[j]==true && isInclude(numKeys, j, i)){
                existSubset = true;
                break;
            }
        }
        if(existSubset)continue;
        bool isKey = true;
        for(int a=0;a<len;a++){
            for(int b=a+1;b<len;b++){
                int count = 0;
                for(int k=0;k<numKeys;k++){
                    if((i&(1<<k))>0){
                        if(relation[a][k]!=relation[b][k]){
                            count++;
                        } 
                    }
                } 
                if(count==0)
                    isKey = false;
            }
        }
        if(isKey){
            keys[i] = true;
            answer++;
        }
    }
    return answer;
}
