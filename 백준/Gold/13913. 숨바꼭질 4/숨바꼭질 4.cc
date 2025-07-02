#include <iostream>
#include <queue>
#include <deque>
using namespace std;

bool visited[100001] = {};
const int INF = 100000;

struct path {
	path* parent = nullptr;
	int count;
	int pos;
	path(int _pos, int _c) : pos(_pos), count(_c) {}
};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n, k;
	cin >> n >> k;

	int answer = 0;

	queue<pair<int,path*>> q;
	path* p = new path(n, 0);
	q.push({ n,p });
	visited[n] = true;

	path* index = nullptr;

	while (!q.empty()) {
		pair<int, path*> x = q.front();
		q.pop();

		if (x.first == k) {
			answer = x.second->count;
			index = x.second;
			break;
		}

		for (int i = 0; i < 3; i++) {
			int nx = x.first;
			if (i == 0)
				nx++;
			else if (i == 1)
				nx--;
			else
				nx *= 2;

			if (nx < 0 || nx > INF)
				continue;

			if (visited[nx])
				continue;

			path* p = new path(nx, x.second->count + 1);
			p->parent = x.second;
			q.push({ nx, p });
			visited[nx] = true;
		}
	}

	cout << answer << '\n';

	deque<int> result;
	while (index != nullptr) {
		result.push_front(index->pos);
		path* prev = index->parent;
		delete index;
		index = prev;
	}

	for (const auto& pos : result)
		cout << pos << ' ';

	return 0;
}