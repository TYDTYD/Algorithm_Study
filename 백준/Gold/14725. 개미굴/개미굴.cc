#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <unordered_map>
using namespace std;

int root = 1;
const int mx = 1000 * 15 * 15 + 5;
bool check[mx];
int trie[mx][26];
unordered_map<string, int> m;
unordered_map<int, string> result;
int unused;

void insert(vector<string>& s) {
	bool leaf = true;
	int cur = root;
	for (const auto& c:s) {
		if (trie[cur][m[c]] == -1) {
			trie[cur][m[c]] = unused++;
		}
		cur = trie[cur][m[c]];
	}
	check[cur] = true;
}

void dfs(int x, int depth) {
	for (int i = 0; i < 26; i++) {
		if (trie[x][i] != -1) {
			for (int i = 0; i < depth; i++)
				cout << "--";
			cout << result[i] << '\n';
			dfs(trie[x][i], depth + 1);
		}
	}
	return;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	vector<vector<string>> eating(n, vector<string>());
	unused = 2;
	fill(check, check + mx, false);
	for (int i = 0; i < mx; i++)
		fill(trie[i], trie[i] + 26, -1);
	set<string> info;
	int num = 0;
	for (int i = 0; i < n; i++) {
		int k;
		cin >> k;
		for (int j = 0; j < k; j++) {
			string eat;
			cin >> eat;
			eating[i].emplace_back(eat);
			info.insert(eat);
		}
	}
	for (const auto& i : info) {
		result[num] = i;
		m[i] = num++;
	}
	for (auto& eat : eating) {
		insert(eat);
	}
	dfs(root, 0);
	return 0;
}