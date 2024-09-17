#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	unordered_map<string, pair<int, int>> m;
	bool toggle[1001] = {};
	int l, securityNum, seq;
	cin >> l >> securityNum >> seq;
	
	for (int i = 0; i < securityNum; i++) {
		int a, d;
		string guard;
		cin >> guard >> a >> d;
		m[guard] = { a,d };
	}
	int count = 0;

	for (int i = 0; i < seq; i++) {
		string index;
		cin >> index;
		pair<int, int> x = m[index];
		int count = x.first;
		toggle[count] = !toggle[count];
		while (l >= count) {
			count += x.second;
			toggle[count] = !toggle[count];
		}
	}

	int answer = 0;
	for (int i = 1; i <= l; i++) {
		if (toggle[i])
			answer++;
	}
	cout << answer;
	return 0;
}