using namespace std;
#include <iostream>
#include <vector>
#define INF 100000000

int N;
int arr[30][30];
vector <int> start(10,0);
vector <int> link(10,0);
int result;
int answer=INF;

int getTeamPoint(vector<int> a) {
	int sum=0;

	for (int i = 0; i < N/2; i++) {
		for (int j = 0; j < N/2; j++) {
			sum += arr[a[i]][a[j]];
		}
	}
	return sum;
}

void solve2() {
	int startIdx = 0;
	int linkIdx = 0;

	for (int i = 0; i < N; i++) {
		if (start[startIdx] == i)
			startIdx++;
		else {
			link[linkIdx] = i;
			linkIdx++;
		}
	}
}

void solve1(int n, int index) {
	if (n == N / 2) {
		solve2();

		int result = abs(getTeamPoint(start) - getTeamPoint(link));

		if (answer > result) 
			answer = result;
		return;
	}
	for (int i = index; i < N; i++) {
		start[n] = i;
		solve1(n+1,i+1);
	}
	return;
}

int main() {

	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
		}
	}

	solve1(0,0);

	cout << answer;
	return 0;
}