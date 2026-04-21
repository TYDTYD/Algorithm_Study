#include <iostream>
#include <queue>
#include <vector>
#define INF 10000000
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

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int v, e, d[20003] = {};
	cin >> v >> e;

	fill(d, d + 20003, INF);
	priority_queue<node, vector<node>, cmp> q;
	vector<vector<node>> graph(v+1, vector<node>());
	
	int start;
	cin >> start;
	for (int i = 0; i < e; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		graph[a].push_back(node(b, c));
	}

	d[start] = 0;
	q.push(node(start, 0));

	while (!q.empty()) {
		node t = q.top();
		q.pop();
		if (d[t.num] < t.distance)
			continue;
		for (const auto& g : graph[t.num]) {
			int cost = t.distance + g.distance;
			if (cost < d[g.num]) {
				d[g.num] = cost;
				q.push(node(g.num,cost));
			}
		}
	}

	for (int i = 1; i < v+1; i++) {
		if (i == start)
			cout << 0 << '\n';
		else if (d[i] == INF)
			cout << "INF" << '\n';
		else
			cout << d[i] << '\n';
	}

	return 0;
}