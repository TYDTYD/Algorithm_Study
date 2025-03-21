#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	ll n;
	cin >> n;
	ll idx = n;
	vector<ll> v;
	for (ll i = 2; i*i <= idx; i++) {
		if (idx % i == 0) {
			while (idx % i == 0)
				idx /= i;
			v.push_back(i);
		}
	}
	if (idx != 1)
		v.push_back(idx);
	ll answer = n;
	for (const auto& e : v)
		answer *= (1 - 1 / (double)e);
	cout << answer;
	return 0;
}