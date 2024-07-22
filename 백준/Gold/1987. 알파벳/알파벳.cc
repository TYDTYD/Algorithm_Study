using namespace std;

#include <iostream>
#include <string>
#define INF -10000

string a[20];
bool visited[30];
int R, C;
int answer=INF;
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

void solve(int n, int m, int count) {
	int nx, ny;
	visited[(int)(a[n][m] - 'A')] = true;
	if (answer < count)
		answer = count;
	
	for (int i = 0; i < 4; i++) {
		nx = n + dx[i];
		ny = m + dy[i];

		if (nx < 0 || nx >= R || ny < 0 || ny >= C)
			continue;
		if (!visited[(int)(a[nx][ny] - 'A')]) {
			solve(nx, ny, count + 1);
			visited[(int)(a[nx][ny] - 'A')] = false;
		}
	}

	return;
}


int main() {
	cin >> R >> C;
	
	for (int i = 0; i < R; i++)
		cin >> a[i];

	solve(0,0,1);

	cout << answer;
}