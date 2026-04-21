using namespace std;

#include <iostream>
#include <stack>
#include <string>

int N;
string a[100];

int solve(int n) {
	for (int i = 0; i < N; i++) {
		stack <char> s;
		for (int j = 0; j < a[i].length(); j++) {
			if(s.empty())
				s.push(a[i][j]);
			else {
				if (s.top() == a[i][j])
					s.pop();
				else
					s.push(a[i][j]);
			}
		}
		if (s.empty())
			n += 1;
	}
	return n;
}

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> a[i];
	}

	cout << solve(0);
}