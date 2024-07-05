#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> tops) {
    int dp[300000] = {1,};
    if(tops[0]==0)
       dp[1]=2;
    else
       dp[1]=3;
    dp[2]=dp[0]+dp[1];
    for(int i=1; i<tops.size(); i++){
        int j=i*2+1;
        if(tops[i]==0){
            dp[j++]=(dp[j-1]+dp[j-2])%10007;
            dp[j]=(dp[j-1]+dp[j-2])%10007;
        }
        else{
            dp[j++]=(2*dp[j-1]+dp[j-2])%10007;
            dp[j]=(dp[j-1]+dp[j-2])%10007;
        }
    }

    return dp[2*n];
}