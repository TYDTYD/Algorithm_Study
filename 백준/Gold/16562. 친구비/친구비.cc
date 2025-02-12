#include <iostream>
#include <vector>
using namespace std;

int find_parent(int n, vector<pair<int, int>>& v) {
	if (n == v[n].first)
		return n;
	return v[n].first = find_parent(v[n].first, v);
}

void merge(int x, int y, vector<pair<int, int>>& v) {
	int parent_x = find_parent(x, v);
	int parent_y = find_parent(y, v);
	if (parent_x == parent_y)
		return;
	if (v[parent_x].second > v[parent_y].second) {
		v[parent_x].first = v[parent_y].first;
	}
	else {
		v[parent_y].first = v[parent_x].first;
	}
	return;
}


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m, k;
	cin >> n >>  m >> k;
	bool we_are_friend[10001] = {};
	vector<pair<int,int>> friend_money;
	friend_money.emplace_back(make_pair(0, 0));
	for (int i = 1; i <= n; i++) {
		int money_element;
		cin >> money_element;
		friend_money.emplace_back(make_pair(i, money_element));
	}
	for (int i = 0; i < m; i++) {
		int v, w;
		cin >> v >> w;
		if (v == w)
			continue;
		merge(find_parent(v, friend_money), find_parent(w, friend_money), friend_money);
	}
	int init_money = k;
	int p = -1, index = 1;
	while (index != n + 1) {
		p = find_parent(friend_money[index++].first, friend_money);
		if (!we_are_friend[p]) {
			k -= friend_money[p].second;
			we_are_friend[p] = true;
		}
	}

	if (k >= 0)
		cout << init_money - k;
	else
		cout << "Oh no";

	return 0;
}