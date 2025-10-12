#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int r, c;
	cin >> r >> c;
	vector<string> card;
	vector<string> temp;
	for(int i = 0; i < r; i++) {
		string result;
		string s;
		cin >> s;
		result = s;
		reverse(s.begin(), s.end());
		result += s;
		card.push_back(result);
	}

	for (int i = r - 1; i >= 0; i--) {
		string s;
		s = card[i];
		card.push_back(s);
	}

	int a, b;
	cin >> a >> b;
	a--, b--;
	if(card[a][b] == '#')
		card[a][b] = '.';
	else
		card[a][b] = '#';

	for(const auto& row : card)
		cout << row << '\n';

	return 0;
}