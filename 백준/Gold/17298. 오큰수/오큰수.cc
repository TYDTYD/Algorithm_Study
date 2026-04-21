#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer;
    int dp[1000000];
    int n=numbers.size()-1, mx=0;
    dp[n]=-1;
    
    for(int i=n-1; i>=0; i--){
        mx=max(mx,numbers[i+1]);
        if(dp[i+1]==-1){
            if(numbers[i]<numbers[i+1])
                dp[i]=numbers[i+1];
            else
                dp[i]=-1;
        }
        else{
            if(numbers[i]<dp[i+1]){
                if(numbers[i]<numbers[i+1])
                    dp[i]=numbers[i+1];
                else
                    dp[i]=dp[i+1];
            }
            else{
                if(numbers[i]<mx){
                    for(int j=i+2; j<n+1; j++){
                        if(dp[j]==-1){
                            dp[i]=numbers[j];    
                            break;
                        }
                        else if(numbers[i]<dp[j]){
                            if(numbers[i]<numbers[j])
                                dp[i]=numbers[j];
                            else
                                dp[i]=dp[j];
                            break;
                        }
                    }
                }
                else
                    dp[i]=-1;
            }
        }
        
    }
    
    for(int i=0; i<numbers.size(); i++){
        answer.push_back(dp[i]);
    }
    
    return answer;
}

int main(){
    int n,m;
    vector<int> number;
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> m;
        number.push_back(m);
    }
    for(auto ans:solution(number))
        cout << ans << " ";
    return 0;
}

