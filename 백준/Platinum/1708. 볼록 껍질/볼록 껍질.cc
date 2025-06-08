using namespace std;

#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>

typedef long long ll;
typedef long double lld;

int N;
int x, y;
vector<pair<ll, ll>> p;
pair<ll, ll> low;
int xIdx = 99999;
int yIdx = 99999;

bool distance(pair<ll, ll> p0, pair<ll, ll> p1, pair<ll, ll> p2) {
	double dist1 = ((p2.first - p0.first) * (p2.first - p0.first)) + ((p2.second - p0.second) * (p2.second - p0.second));
	double dist2 = ((p2.first - p1.first) * (p2.first - p1.first)) + ((p2.second - p1.second) * (p2.second - p1.second));

	if (dist1 > dist2)
		return true;
	else
		return false;
}

double theta(pair<ll, ll> p0, pair<ll, ll> p1) {
	lld dx = p1.first - p0.first;
	lld ax = abs(dx);
	lld dy = p1.second - p0.second;
	lld ay = abs(dy);
	lld t;
	if (ax + ay == 0)
		t = 0;
	else
		t = dy / (ax + ay);
	if (dx < 0)
		t = 2 - t;
	else if (dy < 0)
		t = 4 + t;
	return t * 90;
}

bool compare(pair<ll,ll> a, pair<ll, ll> b) {
	if (theta(low, a) == theta(low, b)) {
		return distance(a, b, low);
	}
	return theta(low, a) < theta(low, b);
}

int ccw(pair<ll, ll> p0, pair<ll, ll> p1, pair<ll, ll> p2) {
	ll result = p0.first * p1.second - p1.first * p0.second + p1.first * p2.second - p2.first * p1.second + p2.first * p0.second - p0.first * p2.second;
	if (result > 0)
		return 1;
	else if (result < 0)
		return -1;
	else
		return 0;
}

int grahamScan() {
	int index = 3;
	stack<int> q;
	sort(p.begin()+1, p.end(), compare);
	
	q.push(0);
	q.push(1);
	q.push(2);

	while (index!=1) {
		int second = q.top();
		q.pop();
		int first = q.top();

		if (ccw(p[first], p[second], p[index])>0) {
			q.push(second);
			q.push(index);
			index += 1;
			if (index == N)
				index = 0;
		}
		else if (ccw(p[first], p[second], p[index]) == 0) {
			q.push(index);
			index += 1;
			if (index == N)
				index = 0;
		}
	}
	
	return q.size() - 1;
}

int main() {
	cin >> N;
	int lowIdx = 0;

	for (int i=0; i < N; i++) {
		cin >> x >> y;
		if (yIdx > y) {
			lowIdx = i;
			xIdx = x;
			yIdx = y;
		}
		else if (yIdx == y) {
			if (xIdx > x) {
				lowIdx = i;
				xIdx = x;
				yIdx = y;
			}
		}
		p.push_back(make_pair(x,y));
	}

	if (N == 3)
		cout << 3 << endl;
	else {
		low = make_pair(xIdx, yIdx);
		p[0].swap(p[lowIdx]);
		cout << grahamScan() << endl;
	}
	
	return 0;
}