#include <iostream>
#include <string>
#include <queue>
#include <vector>
using namespace std;

struct Space{
	int num;
	int x;
	int y;
	int day;
	Space(int n, int _x, int _y, int _d) {
		num = n;
		x = _x;
		y = _y;
		day = _d;
	}
};

bool visited[1501][1501], iceVisited[1501][1501];
int beforeVisit[1501][1501];
int dx[4] = { 1,-1,0,0 }, dy[4] = { 0,0,1,-1 };
queue<Space> pos;
vector<int> space;
vector<vector<int>> v(1501, vector<int>(1501, -1));
int answer = 1, space1 = -1, space2 = -1;

int find_parent(int n) {
	if (space[n] == n)
		return n;
	return space[n] = find_parent(space[n]);
}

bool merge(int x, int y) {
	int parentX = find_parent(x);
	int parentY = find_parent(y);
	if (parentX != parentY) {
		if (parentX == space1 && parentY == space2) {
			space[parentY] = parentX;
			return true;
		}
		else if (parentX == space2 && parentY == space1) {
			space[parentX] = parentY;
			return true;
		}
		else if (parentX == space1 || parentX == space2)
			space[parentY] = parentX;
		else if (parentY == space2 || parentY == space1)
			space[parentX] = parentY;
		else
			space[parentX] = parentY;
	}
	return false;
}

void count_Bfs(int R, int C, int x, int y, vector<string>& lake) {
	int dayIndex = 0;
	while (!pos.empty()) {
		int x = pos.front().x;
		int y = pos.front().y;
		int n = pos.front().num;
		int d = pos.front().day;
		if (d != dayIndex) {
			dayIndex = d;
			if (find_parent(space1) == find_parent(space2)) {
				answer = dayIndex-1;
				return;
			}
		}
		pos.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || nx >= R || ny < 0 || ny >= C)
				continue;
			if (visited[nx][ny] && !iceVisited[nx][ny] && find_parent(v[nx][ny]) != find_parent(n)) {
				iceVisited[nx][ny] = true;
				if (merge(v[nx][ny], n) && beforeVisit[nx][ny]!=d) {
					answer = d - 1;
					return;
				}
				continue;
			}
			if (visited[nx][ny])
				continue;
			pos.emplace(n, nx, ny, d + 1);
			visited[nx][ny] = true;
			beforeVisit[nx][ny] = d;
			lake[nx][ny] = '.';
			v[nx][ny] = n;
		}
	}
	if (find_parent(space1) == find_parent(space2))
		answer = dayIndex - 1;
	return;
}

void bfs(int R, int C, int x, int y, int num, bool& swan, vector<string>& lake) {
	queue<Space> q;
	q.emplace(num, x, y, 0);
	visited[x][y] = true;
	if (lake[x][y] == 'L')
		swan = true;
	while (!q.empty()) {
		int x = q.front().x;
		int y = q.front().y;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || nx >= R || ny < 0 || ny >= C)
				continue;
			if (visited[nx][ny])
				continue;
			if (lake[nx][ny] == 'L')
				swan = true;
			else if (lake[nx][ny] == 'X') {
				pos.emplace(num, x, y, 1);
				continue;
			}
			q.emplace(num, nx, ny, 0);
			visited[nx][ny] = true;
			iceVisited[nx][ny] = true;
			v[nx][ny] = num;
		}
	}
	return;
}


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int R, C;
	cin >> R >> C;
	vector<string> lake;
	for (int i = 0; i < R; i++) {
		string s;
		cin >> s;
		lake.emplace_back(s);
	}
	int num = 0;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			bool swan = false;
			if (lake[i][j] == 'X')
				continue;
			if (visited[i][j])
				continue;
			space.emplace_back(num);
			v[i][j] = num;
			bfs(R, C, i, j, num++, swan, lake);
			if (swan && space1 == -1)
				space1 = num - 1;
			else if (swan)
				space2 = num - 1;
		}
	}

	if (pos.empty())
		cout << 0;
	else {
		count_Bfs(R, C, pos.front().x, pos.front().y, lake);
		cout << answer;
	}
	return 0;
}