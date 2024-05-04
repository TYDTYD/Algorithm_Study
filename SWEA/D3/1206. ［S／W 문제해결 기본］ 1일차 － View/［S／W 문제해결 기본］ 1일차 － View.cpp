#include<iostream>
using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T=10;

	for(test_case = 1; test_case <= T; ++test_case)
	{
        int n;
        cin >> n;
        int h[1001]={};
        for(int i=0; i<n; i++){
            cin >> h[i];
        }
        
        int high1,high2=0, pos=2, answer=0;
        while(pos!=n-2){
            int cur=h[pos], high;
            high1=max(h[pos-1],h[pos-2]);
            high2=max(h[pos+1],h[pos+2]);
            high=max(high1,high2);
            if(cur>high)
                answer+=(cur-high);
            pos++;
        }
        cout << '#' << test_case << ' ' << answer << '\n';
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}