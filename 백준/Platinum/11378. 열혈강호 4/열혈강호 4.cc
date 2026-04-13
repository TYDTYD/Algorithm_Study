#include <iostream> 
#include <queue> 
#include <vector> 
#include <algorithm> 
#define INF 1e9
using namespace std;

struct Edge
{
	int to, flow, capacity;
	Edge* rev;
};

void AddEdge(int u, int v, int cap, vector<vector<Edge*>>& graph)
{
	Edge* e1 = new Edge{ v, 0, cap, nullptr };
	Edge* e2 = new Edge{ u, 0, 0, e1 };
	e1->rev = e2;
	graph[u].push_back(e1);
	graph[v].push_back(e2);
}
vector<int> level(2005), work(2005);

bool bfs(vector<vector<Edge*>>& graph, int s, int t) {
	fill(level.begin(), level.end(), -1);
	queue<int> q;
	q.push(s);
	level[s] = 0;
	while (!q.empty())
	{
		int cur = q.front();
		q.pop();
		for (auto e : graph[cur]) {
			if (level[e->to] == -1 && e->flow < e->capacity) {
				level[e->to] = level[cur] + 1;
				q.push(e->to);
			}
		}
	}
	return level[t] != -1;
}

int dfs(vector<vector<Edge*>>& graph, int cur, int t, int flow) {
	if (cur == t)
		return flow;

	for (int& i = work[cur]; i < graph[cur].size(); i++) {
		auto e = graph[cur][i];
		if (level[e->to] == level[cur] + 1 && e->flow < e->capacity) {
			int curr_flow = min(flow, e->capacity - e->flow);
			int temp_flow = dfs(graph, e->to, t, curr_flow);
			if (temp_flow > 0)
			{
				e->flow += temp_flow;
				e->rev->flow -= temp_flow;
				return temp_flow;
			}
		}
	}
	return 0;
}

int maxFlow(vector<vector<Edge*>>& graph, int s, int t) {
	int total = 0;

	while (bfs(graph, s, t)) {
		fill(work.begin(), work.end(), 0);
		while (true) {
			int flow = dfs(graph, s, t, INF);
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

	vector<vector<Edge*>> graph(2005);

	for (int i = 1; i <= n; i++) {
		int num;
		cin >> num;
		AddEdge(s, i, 1, graph);
		AddEdge(extra, i, k, graph);
		for (int j = 0; j < num; j++) {
			int task;
			cin >> task;
			AddEdge(i, task + 1000, 1, graph);
		}
	}

	for (int task = 1; task <= m; task++)
		AddEdge(task + 1000, t, 1, graph);

	AddEdge(s, extra, k, graph);

	int answer = maxFlow(graph, s, t);
	cout << answer;

	return 0;
}