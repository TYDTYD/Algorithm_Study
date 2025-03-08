#include <iostream>
#include <vector>
#include <algorithm>
#define MOD 1000000007 
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	long long answer = 0;
	vector<long long> v;
	for (int i = 0; i < n; i++) {
		long long s;
		cin >> s;
		v.emplace_back(s);
	}
	sort(v.begin(), v.end());
	
	for (int i = 1; i < n; i++) {
		long long count = 1;
		for (int j = 1; j <= i; j++) {
			count %= MOD;
			answer += ((v[i] - v[i - j]) * count) % MOD;
			answer %= MOD;
			count <<= 1;
		}
	}
	cout << answer;
	return 0;
}