#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>
using namespace std;

#define INF 10000000
vector<int> d;
bool visited[10001];
int v, e, a, b, c;

class compare {
public:
	bool operator()(const pair<int, int>& a, const pair<int, int>& b) {
		return a.first > b.first;
	}
};

int prim(vector<vector<pair<int, int>>> graph, int start) {
	int count = 0;
	d[start] = 0;
	priority_queue<pair<int, int>, vector<pair<int, int>>, compare> h;
	h.push(make_pair(0, start));
	int answer = 0;
	while (v>count) {
		pair<int,int> u = h.top(); // h에는 가중치, 시작점 삽입
		h.pop();
		if (visited[u.second])
			continue;
		count += 1;
		visited[u.second] = true;
		for (auto& i : graph[u.second]) { // graph에는 도착점,가중치
			if (!visited[i.first] && i.second < d[i.first]) { // i.first=>도착점, i.second=>가중치
				d[i.first] = i.second;
				h.push(make_pair(i.second, i.first)); // h에 i.second,i.first 삽입
			}
		}
	}
	for (const auto sum : d) {
		answer += sum;
	}
	return answer;
}

int main() {
	cin >> v >> e;

	vector<vector<pair<int,int>>> graph;
	
	for (int i = 0; i < v; i++) {
		graph.push_back(vector<pair<int, int>>());
		d.push_back(INF);
	}
		

	for (int i = 0; i < e; i++) {
		cin >> a >> b >> c;
		graph[a - 1].push_back(make_pair(b - 1, c));
		graph[b - 1].push_back(make_pair(a - 1, c));
	}

	cout << prim(graph, 0);
}