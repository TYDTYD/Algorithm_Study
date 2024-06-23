#include <iostream>
#include <math.h>
#include <unordered_set>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int c, answer[1001] = {};
	unordered_set<double> s;
	cin >> c;

	for (double i = 1; i < 1001; i++) {
		for (double j = i; j < 1001; j++) {
			if (s.find(tan(i / j)) == s.end()) {
				s.insert(tan(i / j));
				answer[int(max(i, j))] += 2;
			}
		}
	}
	
	for (int i = 2; i <= 1000; i++) 
		answer[i] += answer[i-1];

	
	for (int i = 0; i < c; i++) {
		int n;
		cin >> n;
		cout << answer[n]+1 << '\n';
	}
	
	return 0;
}