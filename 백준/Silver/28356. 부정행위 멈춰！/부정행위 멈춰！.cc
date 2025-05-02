#include <iostream>
#include <set>
using namespace std;

int desk[1000][1000];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m;
	cin >> n >> m;

	int dx[8] = { 1,0,-1,0,-1,-1,1,1 };
	int dy[8] = { 0,1,0,-1,1,-1,1,-1 };
	set<int> s;
	int answer = 1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			set<int> around;
			for (int k = 0; k < 8; k++) {
				int nx = i + dx[k];
				int ny = j + dy[k];
				if (nx<0 || nx>=n || ny<0 || ny>=m)
					continue;
				if (desk[nx][ny])
					around.insert(desk[nx][ny]);
			}
			int check = 1;
			while (around.find(check) != around.end()) {
				check++;
			}
			desk[i][j] = check;
			s.insert(check);
		}
	}

	cout << s.size() << '\n';
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << desk[i][j] << ' ';
		}
		cout << '\n';
	}

	return 0;
}