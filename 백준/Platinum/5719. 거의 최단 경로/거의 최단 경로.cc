#include <iostream>
#include <queue>
#include <vector>
#define INF 1e9
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m;
	while (cin >> n >> m) {
		if (n == 0 && m == 0)
			break;
		int s, d;
		cin >> s >> d;

		vector<vector<pair<int, int>>> graph(n + 1);
		vector<vector<int>> reverse_graph(n + 1);
		for (int i = 0; i < m; i++) {
			int u, v, p;
			cin >> u >> v >> p;
			graph[u].push_back({ v,p });
		}

		int dist[501];
		bool NotAvailable[501][501];
		fill(dist, dist + n + 1, INF);
		for (int i = 0; i <= n; i++)
			fill(NotAvailable[i], NotAvailable[i] + n + 1, false);
		priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
		vector<pair<int,int>> tmp;
		dist[s] = 0;
		pq.push({ 0,s });


		while (!pq.empty()) {
			pair<int,int> cur = pq.top();
			pq.pop();
			if (dist[cur.second] < cur.first)
				continue;
			for (const auto& next : graph[cur.second]) {
				int cost = cur.first + next.second;
				if (cost <= dist[next.first]) {
					if (cost < dist[next.first]) {
						dist[next.first] = cost;
						pq.push({ cost, next.first });
						reverse_graph[next.first].clear();
						reverse_graph[next.first].push_back(cur.second);
					}
					else
						reverse_graph[next.first].push_back(cur.second);
				}
			}
		}

		queue<int> q;
		q.push(d);
		bool visited[501] = {};

		while (!q.empty()) {
			int node = q.front();
			q.pop();
			for (const auto& prev : reverse_graph[node]) {
				NotAvailable[prev][node] = true;
				if (!visited[prev]) {
					visited[prev] = true;
					q.push(prev);
				}
			}
		}

		fill(dist, dist + n + 1, INF);
		dist[s] = 0;
		pq.push({ 0,s });

		while (!pq.empty()) {
			pair<int, int> cur = pq.top();
			pq.pop();
			if (dist[cur.second] < cur.first)
				continue;
			for (const auto& next : graph[cur.second]) {
				if (NotAvailable[cur.second][next.first])
					continue;
				int cost = cur.first + next.second;
				if (cost < dist[next.first]) {
					dist[next.first] = cost;
					pq.push({ cost, next.first });
				}
			}
		}

		if (dist[d] == INF)
			cout << -1 << '\n';
		else
			cout << dist[d] << '\n';
	}
	return 0;
}