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
	long long pow[300001];
	long long plus = 0;
	long long minus = 0;
	long long p = 1;
	vector<long long> v;
	for (int i = 1; i <= n; i++) {
		long long s;
		cin >> s;
		v.emplace_back(s);
		pow[n - i] = p - 1;
		p *= 2;
		p %= MOD;
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < n; i++) {
		plus += (pow[i] * v[n - 1 - i]) % MOD;
		minus += (pow[i] * v[i]) % MOD;
		plus %= MOD;
		minus %= MOD;
	}
	cout << (plus % MOD + MOD - minus % MOD) % MOD;
	return 0;
}