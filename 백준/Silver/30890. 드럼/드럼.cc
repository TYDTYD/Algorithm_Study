#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int x, y, i = 0, j = 0;
	cin >> x >> y;
	int resultL[10001] = {}, resultR[10001] = {};
	vector <int> answer;

	while (j != x)
		resultL[y * j++] = 1;

	while (i!=y)
		resultR[x * i++] = 1;
	
	for (int i = 0; i < x * y; i++) {
		if (resultL[i] && resultR[i]) 
			answer.push_back(3);
		else if (resultL[i])
			answer.push_back(1);
		else if (resultR[i])
			answer.push_back(2);
	}
	
	reverse(answer.begin(), answer.end());
	for (auto ans : answer)
		cout << ans;

	return 0;
}