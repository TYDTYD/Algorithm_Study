#include<iostream>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;
    
	cin>>T;

	for(test_case = 1; test_case <= T; ++test_case)
	{
        int n, p;
        cin >> n >> p;
        int h = n*(n+1) / 2;
        int answer = h;
        
		if(p==h)
            answer--;
        else if(h>p){
            while(p<h)
                h-=n--;
            if(p==h)
                answer--;
        }
		cout << answer << '\n';
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}