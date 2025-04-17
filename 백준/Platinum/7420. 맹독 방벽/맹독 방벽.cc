using namespace std;

#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <math.h>

#define PI 3.1415926535

typedef long long ll;
typedef long double lld;

int N, L;
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

double dist(pair<ll, ll> p0, pair<ll, ll> p1) {
	double distance = ((p1.first - p0.first) * (p1.first - p0.first)) + ((p1.second - p0.second) * (p1.second - p0.second));
	return sqrt(distance);
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

bool compare(pair<ll, ll> a, pair<ll, ll> b) {
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

double grahamScan() {
	int index = 3;
	double result = 0;
	stack<int> q;
	vector<pair<pair<ll, ll>, int>> count;
	sort(p.begin() + 1, p.end(), compare);

	q.push(0);
	q.push(1);
	q.push(2);

	for (int i = 0; i < N; i++)
		count.push_back(make_pair(p[i], i));

	while (index != 1) {
		int second = q.top();
		q.pop();
		int first = q.top();

		if (ccw(p[first], p[second], p[index]) > 0) {
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

	while (q.size()>1) {
		pair<ll, ll> p1;
		pair<ll, ll> p2;
		p1 = make_pair(p[q.top()].first, p[q.top()].second);
		q.pop();
		p2 = make_pair(p[q.top()].first, p[q.top()].second);
		result += dist(p1, p2);
	}

	return result;
}

int main() {
	cin >> N >> L;
	int lowIdx = 0;

	for (int i = 0; i < N; i++) {
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
		p.push_back(make_pair(x, y));
	}

	if (N == 3)
		cout << round(dist(p[0], p[1]) + dist(p[1], p[2]) + dist(p[2], p[0]) + 2 * PI * L);
	else {
		low = make_pair(xIdx, yIdx);
		p[0].swap(p[lowIdx]);
		cout << round(grahamScan() + 2 * PI * L);
	}
	return 0;
}