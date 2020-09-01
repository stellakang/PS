#include <iostream>
#include <string>

using namespace std;

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int M;
    cin>>M;
    string str;
    int x;
    int n = 0;
    while(M--){
        cin>>str;
        if(str!="all" && str!="empty"){
            cin>>x;
        }
        if(str=="add")n|=(1<<x);
        else if(str=="remove")n &= ~(1<<x);
        else if(str=="check")n&(1<<x)? cout<<"1\n": cout<<"0\n";
        else if(str=="toggle")n^=(1<<x);
        else if(str=="all")n = (1<<21) -1;
        else n = 0;
    }
    
    return 0;
}
