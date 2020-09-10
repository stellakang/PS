#include <string>
#include <sstream>
#include <unordered_map>
#include <vector>

using namespace std;

struct types{
    int t;//1: Enter, 2: id
    string id;
};

vector<string> solution(vector<string> record) {
    vector<string> answer;
    unordered_map<string,string>mapping;
    vector<types>parsing;
    int sz = record.size();
    for(int i=0;i<sz;i++){
        istringstream ss(record[i]);
        string buffer;
        getline(ss, buffer, ' ');
        string type = buffer;
        getline(ss, buffer, ' ');
        string id = buffer;
        if(type=="Enter" || type=="Change"){
            getline(ss, buffer, ' ');
            mapping[id] = buffer; 
            int t = type=="Enter"?1:0;
            parsing.push_back({t, id});
        }
        else{
            parsing.push_back({2, id});
        }
    }
    for(int i=0;i<sz;i++){
        int t = parsing[i].t;
        string id = parsing[i].id;
        if(t==1){
            string message = mapping[id]+"님이 들어왔습니다.";
            answer.push_back(message);
        }
        else if(t==2){
            string message = mapping[id]+"님이 나갔습니다.";
            answer.push_back(message);
        }
    }
    return answer;
}
