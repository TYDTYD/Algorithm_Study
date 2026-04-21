#include <iostream>
#include <algorithm>
using namespace std;
long long dp[100000];
long long number[100000];

int main()
{
    int m;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> number[i];
    }
    for (int j = 0; j < n; j++) {
        dp[j] = 0;
    }
    dp[0] = number[0];

    for (int k = 1; k < n; k++) {
        dp[k] = max<long long>(number[k], number[k] + dp[k - 1]);
    }
    m = dp[0];
    for (int x = 0; x < n-1; x++) {
        if (dp[x+1] > m) {
            m = dp[x+1];
        }
    }
    cout << m;
}