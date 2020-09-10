#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include <cctype>
#include <unordered_map>
#include <algorithm>

using namespace std;

struct page{
    int base;
    int exLink;
    double linkTo;
};

int solution(string word, vector<string> pages) {
    int answer = 0;
    int numOfPages = pages.size();
    unordered_map<string,int>mapping;
    transform(word.begin(), word.end(), word.begin(), ::tolower);
    for(int i=0;i<numOfPages;i++){
        transform(pages[i].begin(), pages[i].end(), pages[i].begin(), ::tolower);
    }
    vector<page>pageInfo(numOfPages);
    //base score
    for(int i=0;i<numOfPages;i++){
        int pos = 0;
        int cnt = 0;
        while(true){
            pos = pages[i].find(word, pos);
            if(pos == string::npos)break;
            if((pos-1<0 || !isalpha(pages[i][pos-1])) && (pos+word.length()>=pages[i].length() || !isalpha(pages[i][pos+word.length()]))){
                cnt++;
            }
            pos++;
        }
        pageInfo[i].base = cnt;
        pageInfo[i].linkTo = 0.0;
    }
    //external link number
    for(int i=0;i<numOfPages;i++){
        int pos = 0;
        int cnt = 0;
        pos = pages[i].find("<meta property=\"og:url",pos);
        pos = pages[i].find("https",pos+1);
        int st = pos;
        pos = pages[i].find("\"/>", pos);
        mapping[pages[i].substr(st, pos-st)] = i;
        while(true){
            pos = pages[i].find("<a href", pos);
            if(pos == string::npos)break;
            cnt++;
            pos++;
        }
        pageInfo[i].exLink = cnt;
    }
    //link score
    bool included[numOfPages][numOfPages];
    memset(included, false, sizeof(included));
    for(int i=0;i<numOfPages;i++){
        int pos = 0;
        while(true){
            pos = pages[i].find("<a href=", pos);
            if(pos == string::npos)break;
            pos = pages[i].find("https", pos+1);
            int st = pos;
            pos = pages[i].find("\">", pos);
            string linkstr = pages[i].substr(st, pos-st);
            if(mapping.find(linkstr)!=mapping.end()){
                int indx = mapping[linkstr];
                included[indx][i] = true;
            }
            pos++;
        }
    }
    for(int i=0;i<numOfPages;i++){
        for(int j=0;j<numOfPages;j++){
            if(included[i][j]){
                pageInfo[i].linkTo += (double)(pageInfo[j].base)/(double)(pageInfo[j].exLink);
            }
        }
    }
    double maxScore = 0.0;
    for(int i=0;i<numOfPages;i++){
        if(maxScore < pageInfo[i].base + pageInfo[i].linkTo){
            answer = i;
            maxScore = pageInfo[i].base + pageInfo[i].linkTo;
        }
    }
    return answer;
}
