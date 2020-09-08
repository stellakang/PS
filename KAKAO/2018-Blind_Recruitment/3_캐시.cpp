#include <string>
#include <deque>
#include <algorithm>
#include <unordered_map>
#include <vector>

using namespace std;

int solution(int cacheSize, vector<string> cities) {
    deque<string>dq;
    unordered_map<string, bool>exist;
    int answer = 0;
    
    for(int i=0;i<cities.size();i++){
        string city = cities[i];
        transform(city.begin(), city.end(), city.begin(), ::tolower);
        if(exist[city]){
            answer++;
            for(int j=0;j<dq.size();j++){
                //최신으로 업데이트
                if(dq[j]==city){
                    dq.erase(dq.begin()+j);
                    dq.push_back(city);
                    break;
                }
            }
        }
        else{
            answer += 5;
            if(cacheSize - dq.size()>0){
                dq.push_back(city);
                exist[city] = true;
            }
            else if(!dq.empty()){
                exist[dq.front()] = false;
                dq.pop_front();
                dq.push_back(city);
                exist[city] = true;
            }
        }
    }
    return answer;
}
