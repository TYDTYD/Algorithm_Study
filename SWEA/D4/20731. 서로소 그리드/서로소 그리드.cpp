#include<iostream>
#include <string>
using namespace std;

int gcd(int a, int b) {
	if (b == 0)
		return a;
	return gcd(b, a % b);
}
int main(int argc, char** argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T;
	string graph[51] = {};
	cin >> T;
	for (int t = 0; t < T; t++) {
		int n;
		cin >> n;
		for (int i = 0; i < n; i++)
			cin >> graph[i];
		bool answer = false;
		for (int k = 0; k <= 440; k++) {
			bool graphOut = false;
			for (int i = 1; i <= n; i++) {
				for (int j = 1; j <= n; j++) {
					if(gcd(i+k,j+k)==1 && graph[i-1][j-1]=='?'){
                        graphOut=true;
                    	break;
                    }
                    else if(gcd(i+k,j+k)!=1 && graph[i-1][j-1]=='1'){
                        graphOut=true;
                    	break;
                    }
                }
                if (graphOut)
					break;
                if(i==n)
                    answer=true;
            }
			if (answer)
				break;
		}

		cout << '#' << (t + 1) << ' ';
		if (answer)
			cout << "YES" << '\n';
		else
			cout << "NO" << '\n';
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}