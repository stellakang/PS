#include <iostream>
#include <algorithm>
using namespace std;

int Answer;

int main(int argc, char** argv)
{
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int T, test_case;
	cin >> T;
	for(test_case = 0; test_case  < T; test_case++)
	{
        int N,K;
        cin>>N>>K;
        int a[N], b[N];
        for(int i=0;i<N;i++){
            cin>>a[i];
        }
        for(int i=0;i<N;i++){
            cin>>b[i];
        }
        sort(a, a+N);
        sort(b, b+N);

        Answer = 0;
        for(int i=0;i<K;i++){
            Answer = max(a[i]+b[K-i-1], Answer);
        }
		cout << "Case #" << test_case+1 << "\n";
		cout << Answer << "\n";
	}
	return 0;
}