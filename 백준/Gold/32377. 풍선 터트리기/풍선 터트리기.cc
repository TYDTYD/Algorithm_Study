#include <iostream>
#include <vector>
#include <algorithm>
typedef long long ll;
using namespace std;

ll findLastNumber(ll x, ll y, ll z, ll m) {
	return m - min(m % x, min(m % y, m % z));
}

ll binary_Search(ll x,ll y,ll z,ll n) {
	ll answer=0;
	ll start = 1, end = 1e18;
	while (start < end) {
		ll mid = (start + end) / 2;
		ll index = 0;
		index += mid / x;
		index += mid / y;
		index += mid / z;
		if (n > index)
			start = mid + 1;
		else if (n < index)
			end = mid;
		else {
			answer = findLastNumber(x, y, z, mid);
			break;
		}
		answer = end;
	}
	return answer;
}

int main() {
	ll n, x, y, z;
	cin >> n >> x >> y >> z;
	vector<pair<ll,char>> v;
	if (n == 1) {
		v.emplace_back(make_pair(x, 'A'));
		v.emplace_back(make_pair(y, 'B'));
		v.emplace_back(make_pair(z, 'C'));
		sort(v.begin(), v.end());
		cout << v.front().second << " win";
		return 0;
	}
	ll number_front, number, number_back;
	number_front = binary_Search(x, y, z, n - 1);
	number = binary_Search(x, y, z, n);
	number_back = binary_Search(x, y, z, n + 1);
	
	if (number != number_back) {
		if (number % z == 0)
			cout << "C win";
		else if (number % y == 0)
			cout << "B win";
		else
			cout << "A win";
	}
	else if(number!=number_front){
		if (number % x == 0)
			cout << "A win";
		else if (number % y == 0)
			cout << "B win";
		else
			cout << "C win";
	}
	else
		cout << "B win";
		
	return 0;
}