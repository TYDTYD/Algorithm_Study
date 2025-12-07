#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> v;

	for (int i = 0; i < n; i++) {
		int e;
		cin >> e;
		v.push_back(e);
	}

	sort(v.begin(), v.end());

	int answer = 4;	

	for (int i = 0; i < n; i++) {
		int result = 0;
		int index = v[i];
		for (int j = i + 1; j < i + 5; j++) {			
			if (j >= n || v[j] > index + 4)
				break;			
			result++;
		}		
		answer = min(answer, 4 - result);
		result = 0;
	}

	cout << answer;

	return 0;
}