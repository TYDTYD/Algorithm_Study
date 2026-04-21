#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<pair<int, int>> chicken;
vector<pair<int, int>> house;

void distance(int idx,vector<int>& result) {
	for (int i = 0; i < house.size(); i++) {
		int d = abs(chicken[idx].first - house[i].first) + abs(chicken[idx].second - house[i].second);
		result[i] = min(result[i], d);
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	vector<vector<int>> city(n,vector<int>(n,0));
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> city[i][j];
			if (city[i][j] == 1)
				house.push_back({ i,j });
			else if (city[i][j] == 2)
				chicken.push_back({ i,j });
		}
	}

	vector<int> p;
	int answer = 1000000;
	for (int i = 0; i < chicken.size(); i++) {
		if (i < m)
			p.push_back(0);
		else
			p.push_back(1);
	}

	do {
		vector<int> result(house.size(), 10000);
		int sum = 0;
		for (int i = 0; i < p.size(); i++) {
			if (p[i] == 0)
				distance(i,result);
		}
		for (auto& r : result)
			sum += r;
		answer = min(answer, sum);
	} while (next_permutation(p.begin(), p.end()));

	cout << answer;

	return 0;
}