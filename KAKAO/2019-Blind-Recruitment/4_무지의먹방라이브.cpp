#include <string>
#include <vector>
#include <algorithm>
using namespace std;

struct food{
    long long num, times;
};
bool comp(food &a, food &b){
    return a.times<b.times;
}
bool visit[200005];
int solution(vector<int> food_times, long long k) {
    long long answer = 0;
    long long N = food_times.size();
    vector<food>foods;
    for(long long i=0;i<N;i++){
        foods.push_back({i+1, food_times[i]});
    }
    sort(foods.begin(), foods.end(), comp);
    long long sum = 0;
    for(long long i=0;i<foods.size();i++){
        if(k>=(foods[i].times-sum)*N){
            k -= (foods[i].times-sum)*N;
            sum += foods[i].times-sum;
            visit[foods[i].num] = true;
            N--;
        }
        else{
            k %= N;
            for(long long j=1;j<=foods.size();j++){
                if(visit[j])continue;
                if(k==0){
                    return j;
                }
                k--;
            }
        }
    }
    return -1;
}
