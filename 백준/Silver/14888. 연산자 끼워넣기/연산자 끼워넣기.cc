using namespace std;
#include <iostream>
#define INF -10000000000

int N;
long long result;
long long number[20];
long long calc[20];
long long mx = INF;
long long mn = INF;

void solve(int n);

void p(int n) {
	if (calc[0] == 0)
		return;
	calc[0] -= 1;
	result += number[n];
	solve(n);
	calc[0] += 1;
	result -= number[n];
}

void m(int n) {
	if (calc[1] == 0)
		return;
	calc[1] -= 1;
	result -= number[n];
	solve(n);
	calc[1] += 1;
	result+= number[n];
}

void multiple(int n) {
	if (calc[2] == 0)
		return;
	calc[2] -= 1;
	result*= number[n];
	solve(n);
	calc[2] += 1;
	result /= number[n];
}

void divide(int n) {
	long long idx;
	if (calc[3] == 0)
		return;
	calc[3] -= 1;
	idx = result % number[n];
	result /= number[n];
	solve(n);
	calc[3] += 1;
	result = result * number[n] + idx;
	
}

void solve(int n) {
	if (n == N-1){
		if (mn == INF) {
			mn = result;
		}
		else if(mn>result) {
			mn = result;
		}
		if (mx == INF) {
			mx = result;
		}
		else if (mx < result) {
			mx = result;
		}
		return;
	}

	p(n + 1);
	m(n + 1);
	multiple(n + 1);
	divide(n + 1);
	return;
}

int main() {
	cin >> N;

	for (int i = 0; i < N; i++) 
		cin >> number[i];
	for (int i = 0; i < 4; i++) 
		cin >> calc[i];

	result = number[0];
	solve(0);

	cout << mx << endl << mn;
	
	return 0;
}