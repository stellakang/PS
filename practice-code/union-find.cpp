#include <iostream>
#define SIZE 10000
using namespace std;

/*
    basic version
*/
int root[SIZE];
void init(){
    for(int i=0;i<SIZE;i++){
        root[i] = i;
    }
}
//time complexity : worst O(N)
int find(int x){
    if(root[x] == x){
        return x;
    }
    else{
        return find(root[x]);
    }
}
void union1(int x, int y){
    x = find2(x);
    y = find2(y);
    root[y] = x;
}
/* 
    optimize find
*/
//path compression
//time complexity : O(logN)
int find2(int x){
    if(root[x] == x){
        return x;
    }
    else{
        return root[x] = find2(root[x]);
    }
}
/* 
    optimize union
*/
int ranks[SIZE];
void init2(){
    for(int i=0;i<SIZE;i++){
        root[i] = i;
        ranks[i] = 0;
    }
}
//union by rank
void union2(int x, int y){
    x = find(x);
    y = find(y);

    if(x==y)
        return;
    
    if(ranks[x] < ranks[y]){
        root[x] = y;
    }
    else{
        root[y] = x;
        if(ranks[x] == ranks[y]){
            ranks[x] ++;
        }
    }
}
