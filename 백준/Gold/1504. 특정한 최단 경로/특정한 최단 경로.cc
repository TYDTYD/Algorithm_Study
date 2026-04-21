#include <iostream>
#include <queue>
#include <vector>
#define INF 10000001
using namespace std;

struct node {
	int num;
	int distance = 0;
	node(int a, int b) : num(a), distance(b) {}
};

struct cmp {
	bool operator()(node& a, node& b) {
		return a.distance > b.distance;
	}
};

int v, e, d[803] = {};
priority_queue<node, vector<node>, cmp> q;


void dickstra(int start, vector<vector<node>>& graph, int u, int v) {
	fill(d, d + 803, INF);
	d[start] = 0;
	q.push(node(start, 0));

	while (!q.empty()) {
		node t = q.top();
		q.pop();
		if (d[t.num] < t.distance)
			continue;
		for (const auto& g : graph[t.num]) {
			long long cost = t.distance + g.distance;
			if (cost < d[g.num]) {
				d[g.num] = cost;
				q.push(node(g.num, cost));
			}
		}
	}
	return;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> v >> e;

	vector<vector<node>> graph(v + 1, vector<node>());
	int start, n, m;
	for (int i = 0; i < e; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		graph[a].push_back(node(b, c));
		graph[b].push_back(node(a, c));
	}

	cin >> n >> m;
	long long dist1, dist2, end1, end2, idx;

	dickstra(n, graph, n, m);
	end1 = d[v];
	dickstra(m, graph, n, m);
	end2 = d[v];
	idx = d[n];
	dickstra(1, graph, n, m);
	dist1 = d[m];
	dist2 = d[n];

	long long result1 = dist1 + idx + end1;
	long long result2 = dist2 + idx + end2;
	long long answer = min(result1, result2);

	if (answer >= INF)
		cout << -1;
	else
		cout << answer;

	return 0;
}