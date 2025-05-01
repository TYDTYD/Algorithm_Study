#include <iostream>
#include <algorithm>
using namespace std;
int main() {
	int T;
	cin >> T;
	for(int i=1; i<=T; i++){
		double x, y, z;
		double triangle[3];
		cin >> x >> y >> z;
		triangle[0] = x;
		triangle[1] = y;
		triangle[2] = z;
		sort(triangle, triangle + 3);
		cout << "Scenario #" << i << ":\n";
		if (triangle[0] * triangle[0] + triangle[1] * triangle[1] == triangle[2] * triangle[2])
			cout << "yes\n";
		else
			cout << "no\n";
		cout << '\n';
	}

	return 0;
}