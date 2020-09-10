#include <string>
#include <vector>
#include <algorithm>
using namespace std;

struct failure{
    int num;
    double rate;
};
bool comp(failure& a, failure& b){
    if(a.rate==b.rate){
        return a.num<b.num;
    }
    return a.rate>b.rate;
}

int cnt[505];
vector<int> solution(int N, vector<int> stages) {
    vector<int> answer(N);
    for(int i=0;i<stages.size();i++){
        int num = stages[i];
        cnt[num]++;
    }
    int sum = cnt[N+1];
    vector<failure>f;
    for(int i=N;i>=1;i--){
        sum += cnt[i];
        double r = 0.0;
        if(sum!=0){
            r = (double)cnt[i]/(double)sum;
        }
        f.push_back({i, r});
    }
    sort(f.begin(), f.end(), comp);
    for(int i=0;i<f.size();i++){
        answer[i] = f[i].num;
    }
    return answer;
}
