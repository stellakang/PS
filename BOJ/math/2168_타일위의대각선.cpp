#include <iostream>
#include <float.h>
using namespace std;

long long int gcd(long long int x, long long int y){
    if(x%y==0)return y;
    return gcd(y, x%y);
}

long long int numberOfDiagonal(long long int x, long long int y){
    if(x<y)return numberOfDiagonal(y,x);
    long long int gcdVal = gcd(x, y);
    long long int xDivGCD = x/gcdVal;
    long long int yDivGCD = y/gcdVal;
    if(gcdVal==1){
        return (x+y-1);
    }
    return gcdVal* numberOfDiagonal(xDivGCD, yDivGCD);
}

int main(){
    long long int x,y;
    scanf("%lld %lld",&x,&y);

    printf("%lld\n",numberOfDiagonal(x,y));

    return 0;
}