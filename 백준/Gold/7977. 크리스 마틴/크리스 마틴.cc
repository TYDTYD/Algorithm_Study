#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

vector<vector<int>> L(10001);

int main() {
	int n;
	char dna[4] = { 'A','C','G','T' };
	cin >> n;
	char str[10001];
	string answer = "";
	vector<pair<int,char>> v(4);
	for (int i = 0; i < 4; i++)
		v[i].second = dna[i];

	for (int i = 0; i < n; i++) {
		cin >> str[i];
		switch (str[i]) {
		case 'A':
			v[0].first++;
			break;
		case 'C':
			v[1].first++;
			break;
		case 'G':
			v[2].first++;
			break;
		case 'T':
			v[3].first++;
			break;
		}
	}
	sort(v.begin(), v.end());
	cout << v.front().first << '\n';
	for(int i=0; i<n; i++)
		answer += v.front().second;
	cout << answer;

	return 0;
}