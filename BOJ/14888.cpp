#include <iostream>
using namespace std;

struct operation{
    int add;//add
    int sub;//subtract
    int mul;//multiply
    int div;//divide
};

void calculate(int N, int number[], operation op, int numIndx, int value);

int maxVal=-100000001;
int minVal=100000001;

int main(){
    int N;
    cin>>N;
    int number[N];
    for(int i=0;i<N;i++){
        cin>>number[i];
    }
    int a,s,m,d;
    cin>>a>>s>>m>>d;
    operation op = {a,s,m,d};
    calculate(N, number, op, 1, number[0]);
    cout<<maxVal<<"\n"<<minVal<<"\n";
    return 0;
}
void calculate(int N, int number[], operation op, int numIndx, int value){
    if(N==numIndx){
        if(value<minVal)
            minVal = value;
        if(value>maxVal)
            maxVal = value;
        return;
    }
    if(op.add>0){
        int addition = value + number[numIndx];
        calculate(N, number,{op.add-1,op.sub, op.mul, op.div}, numIndx+1, addition);
    }
    if(op.sub>0){
        int subtraction = value - number[numIndx];
        calculate(N, number,{op.add,op.sub-1, op.mul, op.div}, numIndx+1, subtraction);
    }
    if(op.mul>0){
        int multi = value * number[numIndx];
        calculate(N, number,{op.add,op.sub, op.mul-1, op.div}, numIndx+1, multi);
    }
    if(op.div>0){
        int division = value / number[numIndx];
        calculate(N, number,{op.add,op.sub, op.mul, op.div-1}, numIndx+1, division);
    }
}

