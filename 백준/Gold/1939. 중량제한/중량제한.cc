#include <iostream>
#include <vector>
#include <unordered_map>
#define INF 1e9
using namespace std;

bool backTracking(int n, int dest, int value, int result, vector<vector<pair<int,int>>>& graph, bool visited[]) {
	visited[n] = true;
	if (n == dest)
		return true;
	for (const auto& i:graph[n]) {
		if (value > i.second)
			continue;
		if (!visited[i.first]) {
			if (backTracking(i.first, dest, value, i.second, graph, visited))
				return true;
		}
	}
	return false;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m;
	cin >> n >> m;

	vector<vector<pair<int, int>>> graph(n + 1);
	unordered_map<int, int> island[10001];
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		if (island[a][b] > c)
			continue;
		graph[a-1].emplace_back(make_pair(b-1, c));
		graph[b-1].emplace_back(make_pair(a-1, c));
	}

	int start, end, answer;
	cin >> start >> end;
	
	int s = 1, e = INF, mid;
	while (s <= e) {
		bool visited[10001] = {};
		mid = (s + e) / 2;
		if (backTracking(start - 1, end - 1, mid, INF, graph, visited)) {
			s = mid + 1;
			answer = mid;
		}
		else
			e = mid - 1;
	}

	cout << answer;

	return 0;
}