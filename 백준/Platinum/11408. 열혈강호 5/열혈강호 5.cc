#include <iostream>
#include <vector>
#include <queue>
#define INF 1e9
using namespace std;

struct Edge {
	int to, capacity, cost, rev;
};

void AddEdge(vector<vector<Edge>>& graph, int from, int to, int capacity, int cost) {
	int revFrom = graph[to].size();
	graph[from].push_back({ to, capacity, cost,  revFrom});
	int revTo = graph[from].size() - 1;
	graph[to].push_back({ from, 0, -cost, revTo});
}

bool spfa(vector<vector<Edge>>& graph, int start, int target, vector<pair<int,int>>& parent) {
	int n = graph.size();
	vector<int> distance(n + 5, INF);
	bool inQueue[805] = {};
	queue<int> q;	
	q.push(start);
	distance[start] = 0;
	inQueue[start] = true;

	while (!q.empty()) {
		int current = q.front();
		q.pop();
		inQueue[current] = false;
		int n = graph[current].size();
		for (int i = 0; i < n; i++) {
			Edge& edge = graph[current][i];

			if (edge.capacity > 0 && distance[edge.to] > distance[current] + edge.cost) {
				distance[edge.to] = distance[current] + edge.cost;
				parent[edge.to] = { current, i };
				if (!inQueue[edge.to]) {
					q.push(edge.to);
					inQueue[edge.to] = true;
				}
			}
		}
	}
	return distance[target] != INF;
}

pair<int,int> MCMF(vector<vector<Edge>>& graph, int start, int target) {
	int maxFlow = 0;		
	int minCost = 0;
	vector<pair<int, int>> path(graph.size() + 5);
	while (spfa(graph, start, target, path)) {
		int flow = INF;
		int costSum = 0;
		for(int i = target; i != start; i = path[i].first) {
			int prev = path[i].first;
			int index = path[i].second;
			Edge& edge = graph[prev][index];
			flow = min(flow, edge.capacity);
			costSum += edge.cost;
		}		

		for (int i = target; i != start; i = path[i].first) {
			int prev = path[i].first;
			int index = path[i].second;
			Edge& edge = graph[prev][index];
			Edge& revEdge = graph[edge.to][edge.rev];
			edge.capacity -= flow;
			revEdge.capacity += flow;			
		}
		minCost += costSum * flow;
		maxFlow += flow;
	}
	
	return { maxFlow, minCost };
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	vector<vector<Edge>> graph(n + m + 5);

	int start = 0;
	int target = n + m + 1;

	for (int i = 1; i <= n; i++) {
		AddEdge(graph, start, i, 1, 0);
		int num;
		cin >> num;
		for (int j = 0; j < num; j++) {
			int job, pay;
			cin >> job >> pay;			
			AddEdge(graph, i, job + n, 1, pay);
		}
	}

	for (int i = n + 1; i <= n + m; i++)
		AddEdge(graph, i, target, 1, 0);	

	pair<int, int> answer = MCMF(graph, start, target);
	cout << answer.first << '\n' << answer.second;
	return 0;
}