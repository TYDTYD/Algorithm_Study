#include <iostream>
#include <unordered_map>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	unordered_map<string, string> hash;
	for (int i = 0; i < n; i++) {
		string s, key = "", tmp = "";
		cin >> s;
		int size = s.length();
		for (int i = 0; i < size; i++) {
			if (i == 0 || i == size - 1) {
				if (i == size - 1) {
					sort(tmp.begin(), tmp.end());
					key += tmp;
				}
				key += s[i];
			}
			else
				tmp += s[i];
		}
		hash[key] = s;
	}

	int m;
	cin >> m;
	
	for (int i = 0; i < m; i++) {
		string s, key = "", tmp = "";
		cin >> s;
		int size = s.length();
		for (int j = 0; j < size; j++) {
			if (j == 0 || j == size - 1) {
				if (j == size - 1) {
					sort(tmp.begin(), tmp.end());
					key += tmp;
				}
				key += s[j];
			}
			else
				tmp += s[j];
		}
		cout << hash[key] << ' ';
	}

	return 0;
}