#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#define INF 1000000000
using namespace std;

vector<vector<int>> flow, capacity, adjList;
vector<int> level, work;

void addEdge(int start, int end, int cap, bool directed) {
	adjList[start].push_back(end);
	adjList[end].push_back(start);
	capacity[start][end] += cap;
	if(!directed) {
		capacity[end][start] += cap;
	}
}

bool bfs(int s, int t) {
	fill(level.begin(), level.end(), -1);
	queue<int> q;
	q.push(s);
	level[s] = 0;
	
	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		for (auto next : adjList[cur]) {
			if (level[next] == -1 && capacity[cur][next] > flow[cur][next]) {				
				q.push(next);
				level[next] = level[cur] + 1;
			}
		}
	}

	return level[t] != -1;
}

int dfs(int cur, int t, int f) {
	if (cur == t)
		return f;

	for (int& i = work[cur]; i < adjList[cur].size(); i++) {
		int next = adjList[cur][i];
		if (level[next] == level[cur] + 1 && capacity[cur][next] - flow[cur][next] > 0) {
			int available = capacity[cur][next] - flow[cur][next];
			int ret = dfs(next, t, min(f, available));

			if (ret > 0) {
				flow[cur][next] += ret;
				flow[next][cur] -= ret;
				return ret;
			}
		}
	}
	return 0;
}

int maxFlow(int n, int s, int t) {
	int total = 0;	

	while (bfs(s, t)) {
		fill(work.begin(), work.end(), 0);
		while (true) {
			int flow = dfs(s, t, INF);
			if (flow == 0)
				break;
			total += flow;
		}
	}
	return total;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m, k;
	cin >> n >> m >> k;

	const int s = 0;
	const int t = 2003;
	const int extra = 2002;

	flow.resize(t + 1, vector<int>(t + 1, 0));
	capacity.resize(t + 1, vector<int>(t + 1, 0));
	adjList.resize(t + 1);
	level.assign(t + 1, -1);
	work.assign(t + 1, 0);

	for (int i = 1; i <= n; i++) {
		int num;
		cin >> num;
		addEdge(s, i, 1, true);
		addEdge(extra, i, 1, true);
		for (int j = 0; j < num; j++) {
			int task;
			cin >> task;
			addEdge(i, 1000 + task, 1, true);
		}
	}

	for (int task = 1; task <= m; task++)
		addEdge(1000 + task, t, 1, true);	

	addEdge(s, extra, k, true);

	int answer = maxFlow(2003, s, t);
	cout << answer;

	return 0;
}