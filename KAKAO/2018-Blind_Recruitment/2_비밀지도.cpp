#include <string>
#include <vector>

using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    for(int i=0;i<n;i++){
        int num = arr1[i]|arr2[i];
        string str;
        for(int j=0;j<n;j++){
            if((num & (1<<j))){
                str = '#' + str;
            }
            else{
                str = ' ' + str;
            }
        }
        answer.push_back(str);
    }
    return answer;
}
