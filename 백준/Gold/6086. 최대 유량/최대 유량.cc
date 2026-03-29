#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#define INF 1e9
using namespace std;

struct Edge {
	int from, to;
	int capacity;
	int flow;
	Edge* rev;	
};

int CharToInt(char c) {
	if (c >= 'a' && c <= 'z')
		return c - 'a' + 26;
	return c - 'A';
}

void AddEdge(int u, int v, int capacity, vector<vector<Edge*>>& graph) {
	Edge* forwardEdge = new Edge{ u, v, capacity, 0, nullptr };
	Edge* backwardEdge = new Edge{ v, u, 0, 0, nullptr };
	forwardEdge->rev = backwardEdge;
	backwardEdge->rev = forwardEdge;
	graph[u].push_back(forwardEdge);
	graph[v].push_back(backwardEdge);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;

	vector<vector<Edge*>> graph(100);
	map<pair<int, int>, Edge*> pipeInfo;

	for (int i = 0; i < n; i++) {
		char from, to;
		int capacity;
		cin >> from >> to >> capacity;
		int fromNum = CharToInt(from);
		int toNum = CharToInt(to);
		AddEdge(fromNum, toNum, capacity, graph);
		AddEdge(toNum, fromNum, capacity, graph);
	}

	int start = CharToInt('A');
	int dest = CharToInt('Z');

	vector<Edge*> pred(100);
	int answer = 0;

	while (true)
	{
		queue<int> q;
		fill(pred.begin(), pred.end(), nullptr);
		q.push(start);

		while (!q.empty() && pred[dest] == nullptr) {
			int cur = q.front();
			q.pop();
			for (const auto edge : graph[cur]) {
				if (pred[edge->to] == nullptr && edge->to != start && edge->capacity > edge->flow) {
					pred[edge->to] = edge;
					q.push(edge->to);
				}
			}
		}

		if (pred[dest] == nullptr)
			break;

		int flow = INF;
		for (auto e = pred[dest]; e != nullptr; e = pred[e->from]) {
			flow = min(flow, e->capacity - e->flow);
		}
		for (auto e = pred[dest]; e != nullptr; e = pred[e->from]) {
			e->flow += flow;
			e->rev->flow -= flow;
		}
		answer += flow;
	}

	cout << answer;
	return 0;
}