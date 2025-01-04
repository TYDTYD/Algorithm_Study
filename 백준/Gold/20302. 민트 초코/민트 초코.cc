#include <iostream>
#include <vector>
using namespace std;


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;
	vector<int> v;
	vector<char> code;
	bool flag = false;
	for (int i = 0; i < 2 * n - 1; i++) {
		int num;
		char c;
		if (i % 2 == 0) {
			cin >> num;
			if (num == 0)
				flag = true;
			else if (num < 0)
				num = -num;
			v.emplace_back(num);
		}
		else {
			cin >> c;
			code.emplace_back(c);
		}
	}

	if (flag) {
		cout << "mint chocolate";
		return 0;
	}

	int index = 0;
	int prime_list_c[100001] = {}, prime_list_p[100001] = {};

	for (int i = 2; i * i <= v[0]; i++) {
		while (v[0] % i == 0) {
			v[0] /= i;
			prime_list_c[i]++;
		}
	}
	if (v[0] > 1)
		prime_list_c[v[0]]++;

	for (int i = 1; i < v.size(); i++) {
		if (code[index] == '*') {
			for (int j = 2; j * j <= v[i]; j++) {
				while (v[i] % j == 0) {
					v[i] /= j;
					prime_list_c[j]++;
				}
			}
			if (v[i] > 1)
				prime_list_c[v[i]]++;
		}
		else {
			for (int j = 2; j * j <= v[i]; j++) {
				while (v[i] % j == 0) {
					v[i] /= j;
					prime_list_p[j]++;
				}
			}
			if (v[i] > 1)
				prime_list_p[v[i]]++;
		}
		index++;
	}
	
	

	for (int i = 0; i < 100001; i++) {
		if (prime_list_c[i] < prime_list_p[i]) {
			cout << "toothpaste";
			return 0;
		}
	}
	
	cout << "mint chocolate";

	return 0;
}