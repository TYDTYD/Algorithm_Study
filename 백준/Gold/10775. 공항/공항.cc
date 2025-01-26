#include <iostream>
#include <vector>
using namespace std;

vector<int> gate;

int find_X(int x) {
	if (x == 0)
		return 0;
	if (x == gate[x]) {
		gate[x] = x - 1;
		return x;
	}
	return gate[x] = find_X(gate[x]);
}

int main() {
	int G, P, answer = 0;
	bool Full = false;
	cin >> G >> P;
	gate.emplace_back(0);

	for (int i = 1; i <= G; i++)
		gate.emplace_back(i);

	for (int i = 0; i < P; i++) {
		int g;
		cin >> g;
		if (find_X(g) == 0)
			Full = true;
		if (!Full)
			answer++;
	}
	cout << answer;

	return 0;
}