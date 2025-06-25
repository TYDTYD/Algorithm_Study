#include <iostream>
using namespace std;

int main() {
	double pos[3][2] = {};
	for (int i = 0; i < 3; i++)
		cin >> pos[i][0] >> pos[i][1];

	if ((pos[1][1] - pos[0][1]) * (pos[2][0] - pos[1][0]) == (pos[2][1] - pos[1][1]) * (pos[1][0] - pos[0][0]))
		cout << "WHERE IS MY CHICKEN?";
	else
		cout << "WINNER WINNER CHICKEN DINNER!";

	return 0;
}