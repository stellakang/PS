#include <string>
#include <algorithm>
#include <vector>
#include <iostream>
#include <unordered_map>
using namespace std;

int solution(string str1, string str2) {
    unordered_map<string, int>one, two;
    vector<string>common, total;
    
    transform(str1.begin(), str1.end(), str1.begin(), ::tolower);
    transform(str2.begin(), str2.end(), str2.begin(), ::tolower);
    
    for(int i=0;i<str1.length()-1;i++){
        if(isalpha(str1[i])==false || isalpha(str1[i+1])==false)continue;
        string str = str1.substr(i,2);
        one[str]++;
    }
    for(int i=0;i<str2.length()-1;i++){
        if(isalpha(str2[i])==false || isalpha(str2[i+1])==false)continue;
        string str = str2.substr(i,2);
        two[str]++;
    }
    double bottom = 0.0, up = 0.0;
    for(auto e: one){
        if(two.find(e.first)!=two.end()){
            up += min(e.second, two[e.first]);
            bottom += max(e.second, two[e.first]);
        }
        else{
            bottom += e.second;
        }
    }
    for(auto e: two){
        if(one.find(e.first)==one.end()){
            bottom += e.second;
        }
    }
    if(bottom==0.0)return 65536;
    int answer = (up/bottom)*65536;
    return answer;
}
