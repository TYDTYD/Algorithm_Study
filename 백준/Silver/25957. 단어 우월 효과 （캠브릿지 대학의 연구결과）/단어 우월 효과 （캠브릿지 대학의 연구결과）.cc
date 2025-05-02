#include <iostream>
#include <map>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	map<string, string> hash;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		string key = "";
		string tmp = "";
		for (int i = 0; i < s.length(); i++) {
			if (i == 0 || i == s.length() - 1) {
				if (i == s.length() - 1) {
					sort(tmp.begin(), tmp.end());
				}
				key += tmp;
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
		string s;
		string key = "";
		string tmp = "";
		cin >> s;
		for (int j = 0; j < s.length(); j++) {
			if (j == 0 || j == s.length() - 1) {
				if (j == s.length() - 1) {
					sort(tmp.begin(), tmp.end());
				}
				key += tmp;
				key += s[j];
			}
			else
				tmp += s[j];
		}
		if (i != m - 1)
			cout << hash[key] << ' ';
		else
			cout << hash[key];
	}

	return 0;
}