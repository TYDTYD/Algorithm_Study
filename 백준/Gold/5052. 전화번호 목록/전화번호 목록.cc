#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int root = 1;
const int mx = 10000*10 + 5;
bool check[mx];
int trie[mx][10];
int unused;
bool flexible;

void insert(string s) {
	bool leaf = true;
	int cur = root;
	for (int i = 0; i < s.size(); i++) {
		if (trie[cur][s[i] - '0'] == -1) {
			trie[cur][s[i] - '0'] = unused++;
			leaf = true;
		}
		else
			leaf = false;
		cur = trie[cur][s[i] - '0'];
		if (!leaf && check[cur]) {
			flexible = false;
			return;
		}
		if (i==s.size()-1 && !leaf)
			flexible = false;
	}
	check[cur] = true;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int n;
		unused = 2;
		fill(check, check + mx, false);
		for (int j = 0; j < mx; j++)
			fill(trie[j], trie[j] + 10, -1);
		cin >> n;
		flexible = true;
		for (int j = 0; j < n; j++) {
			string number;
			cin >> number;
			insert(number);
		}
		if (flexible)
			cout << "YES" << '\n';
		else
			cout << "NO" << '\n';
	}

	return 0;
}