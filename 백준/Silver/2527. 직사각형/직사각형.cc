#include <iostream>
using namespace std;

struct Rect {
	int ax, ay, bx, by;
	Rect(int a, int b, int c, int d) : ax(a), ay(b), bx(c), by(d) {}
};

bool Bcheck(Rect& r1, Rect& r2) {
	if ((r1.by == r2.ay || r1.ay == r2.by) && !(r1.bx <= r2.ax || r2.bx <= r1.ax))
		return true;
	if (r1.bx == r2.ax && !(r1.by <= r2.ay || r2.by <= r1.ay))
		return true;
	return false;
}

bool Ccheck(Rect& r1, Rect& r2) {
	if (r1.ay == r2.by && r1.bx == r2.ax)
		return true;
	if (r1.bx == r2.ax && r1.by == r2.ay)
		return true;
	return false;
}

bool Dcheck(Rect& r1, Rect& r2) {
	if (r1.bx < r2.ax)
		return true;
	if (r1.by < r2.ay)
		return true;
	if (r2.by < r1.ay)
		return true;
	return false;
}

void solve(Rect R1,Rect R2) {
	if (Dcheck(R1, R2))
		cout << "d\n";
	else if (Ccheck(R1, R2))
		cout << "c\n";
	else if (Bcheck(R1, R2))
		cout << "b\n";
	else
		cout << "a\n";
}

int main() {
	for (int i = 0; i < 4; i++) {
		int a1, b1, c1, d1, a2, b2, c2, d2;
		cin >> a1 >> b1 >> c1 >> d1;
		cin >> a2 >> b2 >> c2 >> d2;
		Rect R1(a1, b1, c1, d1);
		Rect R2(a2, b2, c2, d2);
		if (a1 <= a2)
			solve(R1, R2);
		else
			solve(R2, R1);
	}

	return 0;
}