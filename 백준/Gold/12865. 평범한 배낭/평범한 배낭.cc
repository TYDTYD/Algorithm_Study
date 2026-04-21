#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() 
{
	int n, k;

	cin >> n >> k;
	
	int weight[101] = {};
	int value[101] = {};
	int dp[100001];

	fill(dp, dp + 100001, 0);

	for (int i = 0; i < n; i++) {
		int w, v;
		cin >> w >> v;
		weight[i] = w;
		value[i] = v;
	}

	for (int i = 0; i < n; i++) {
		for (int j = k; j >= weight[i]; j--) {
			dp[j] = max(dp[j], dp[j - weight[i]] + value[i]);
		}
	}
	
	cout << dp[k];
}