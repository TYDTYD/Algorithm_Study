#include <iostream>
#include <vector>
using namespace std;

long long gcd(long long x, long long y) {
	while (y != 0) {
		long long temp = y;
		y = x % y;
		x = temp;
	}
	return x;
}

long long gcd(vector<long long>& v) {
	return gcd(gcd(v[0], v[1]), v[2]);
}

int main() {
	long long a, b, c, d;
	cin >> a >> b >> c >> d;
	long long x, y, z;
	cin >> x >> y >> z >> d;
	
	vector<long long> result1,result2,result3,result4;
	
	result1.push_back(a * x);
	result1.push_back(x * b + a * y);
	result1.push_back(c * x + z * a);
	result1.push_back(d);
	
	long long index = gcd(result1);
	long long minus = 1;
	
	if (result1[0]/index < 0)
		minus = -1;
	for (int i = 0; i < 3; i++) {
		result1[i] /= index;
		cout << result1[i]*minus << ' ';
	}
	if (result1[2] == 0)
		cout << 0 << '\n';
	else
		cout << d << '\n';

	result2.push_back(a * x);
	result2.push_back(b * x - a * y);
	result2.push_back(c * x - z * a);
	result2.push_back(d);

	index = gcd(result2);
	minus = 1;
	if (result2[0] / index < 0)
		minus = -1;
	for (int i = 0; i < 3; i++) {
		result2[i] /= index;
		cout << result2[i] * minus << ' ';
	}
	if (result2[2] == 0)
		cout << 0 << '\n';
	else
		cout << d << '\n';
	
	result3.push_back(a * x);
	result3.push_back(b * y + c * z * d);
	result3.push_back(b * z + y * c);
	result3.push_back(d);

	index = gcd(result3);
	minus = 1;
	if (result3[0] / index < 0)
		minus = -1;
	for (int i = 0; i < 3; i++) {
		result3[i] /= index;
		cout << result3[i] * minus << ' ';
	}
	if (result3[2] == 0)
		cout << 0 << '\n';
	else
		cout << d << '\n';

	result4.push_back((a * y) * (a * y) - (a * z) * (a * z) * d);
	result4.push_back(a * y * x * b - x * c * a * z * d);
	result4.push_back(a * y * x * c - a * z * x * b);
	result4.push_back(d);

	index = gcd(result4);
	minus = 1;
	if (result4[0] / index < 0)
		minus = -1;
	for (int i = 0; i < 3; i++) {
		result4[i] /= index;
		cout << result4[i] * minus << ' ';
	}
	if (result4[2] == 0)
		cout << 0 << '\n';
	else
		cout << d << '\n';

	return 0;
}