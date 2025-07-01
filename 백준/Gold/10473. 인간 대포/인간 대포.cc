#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;

struct Pos {
	double x, y;
	Pos(double _x, double _y) : x(_x), y(_y) {}
};

double time(Pos a, Pos b) {
	return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y)) * 0.2;
}

struct cmp {
	bool operator()(pair<int,double>& x, pair<int,double>& y) {
		return x.second > y.second;
	}
};

int main() {
	double x, y, answer = 0;
	cin >> x >> y;
	Pos pos = Pos(x, y);
	cin >> x >> y;
	Pos dest = Pos(x, y);
	int n;
	cin >> n;
	vector<Pos> cannon;
	vector<vector<int>> graph(n + 2);

	for (int i = 0; i < n; i++) {
		double x, y;
		cin >> x >> y;
		cannon.push_back(Pos(x, y));
		for (int j = 0; j < n + 2; j++) {
			if (i == j)
				continue;
			graph[i].push_back(j);
		}
	}

	for (int i = n; i < n+2; i++) {
		for (int j = 0; j < n+2; j++) {
			if (i == j)
				continue;
			graph[i].push_back(j);			
		}
	}

	cannon.push_back(pos);
	cannon.push_back(dest);

	// n은 출발지, n+1은 도착지
	const double INF = 1e9;
	double dist[102] = {};
	fill(dist, dist + 102, INF);
	priority_queue<pair<int,double>, vector<pair<int,double>>, cmp> pq;
	pq.push({ n,0 });
	dist[n] = 0;

	while (!pq.empty()) {
		pair<int, double> cur = pq.top();
		pq.pop();
		if (cur.second > dist[cur.first])
			continue;

		if (cur.first == n + 1) {
			answer = dist[cur.first];
			break;
		}
		for (const auto& node:graph[cur.first]) {
			// 걸어가서 걸리는 시간
			double wTime = time(cannon[cur.first], cannon[node]);
			// 대포탄 뒤 걸어가서 걸리는 시간
			// 만약 대포 사거리 밖에 있다면
			double cTime = 1e9;
			if (wTime > 10)
				cTime = wTime - 8;
			else
				cTime = 12 - wTime;
			double cost = min(wTime, cTime);

			if (cur.first == n)
				cost = wTime;

			if (dist[node] > cost + cur.second) {
				dist[node] = cost + cur.second;
				pq.push({ node,dist[node] });
			}
		}
	}
	
	cout.fixed;
	cout.precision(10);
	cout << answer;

	return 0;
}