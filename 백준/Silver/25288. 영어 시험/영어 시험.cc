#include <iostream>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	string str;
	cin >> n;
	cin >> str;
	for (int i = 0; i < n; i++)
		cout << str;
	
	return 0;
}