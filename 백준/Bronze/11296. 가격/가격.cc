#include <iostream>
#include <cmath>
#include <map>
using namespace std;

void PrintFormat(double value, bool cash) {
	int div = cash ? 10 : 100;
	value = round(value * div) / div;
	cout << "$" << value << '\n';
}

int main() {
	int n;
	cin >> n;

	map<char, double> colorDiscounts;

	colorDiscounts['R'] = 0.45;
	colorDiscounts['G'] = 0.3;
	colorDiscounts['B'] = 0.2;
	colorDiscounts['Y'] = 0.15;
	colorDiscounts['O'] = 0.1;
	colorDiscounts['W'] = 0.05;

	cout << fixed;
	cout.precision(2);

	for (int i = 0; i < n; i++) {
		double price;
		char color;
		char couponChar;
		char cashChar;
		cin >> price >> color >> couponChar >> cashChar;
		bool coupon = couponChar != 'X';
		bool cash = cashChar == 'C';
		price *= (1 - colorDiscounts[color]);		
		if (coupon)
			price *= (1 - 0.05);
		PrintFormat(price, cash);
	}

	return 0;
}