#include <iostream>
#include <string>
using namespace std;

int main(){
    string a,b;
    cin>>a>>b;

    int alen = a.length();
    int blen = b.length();

    int answer = alen;
    for(register int i=0;i<=blen-alen;i++){
        int diff = 0;
        for(register int j=i;j<i+alen;j++){
            if(a[j-i]!=b[j])diff++;
        }
        if(answer>diff)
            answer = diff;
    }
    printf("%d\n",answer);
    return 0;
}