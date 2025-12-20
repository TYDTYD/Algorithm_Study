#include <iostream>
#include <queue>
#include <stack>
#include <vector>
using namespace std;

struct circlePoint {	
	int num;
	long long pos;
	long long radius;
	bool isStart;
	long long inSideRadius = 0;
	bool isInSideCircle = false;
	circlePoint(int n, long long p, long long r, bool s) : num(n), pos(p), radius(r), isStart(s) {}

	bool operator<(const circlePoint& other) const {
		if (pos == other.pos) {
			if (isStart == other.isStart && isStart) {
				return radius < other.radius;
			}
			else if(isStart == other.isStart && !isStart) {
				return radius > other.radius;
			}
			return isStart > other.isStart;
		}
		return pos > other.pos;
	}
};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;	

	priority_queue<circlePoint, vector<circlePoint>> pq;
	vector<circlePoint*> circles(n);	

	for (int i = 0; i < n; i++) {
		long long x, r;
		cin >> x >> r;
		pq.push(circlePoint(i, x - r, r, true));
		pq.push(circlePoint(i, x + r, r, false));
		circles[i] = new circlePoint(i, x, r, false);
	}

	int answer = 1;
	stack<circlePoint> stk;

	while(!pq.empty()) {
		circlePoint current = pq.top();		
		pq.pop();		
		if (current.isStart) {
			stk.push(current);
		}
		else {
			if (!stk.empty() && stk.top().num == current.num) {
				stk.pop();
				if (!stk.empty()) {
					int parent = stk.top().num;
					circles[parent]->inSideRadius += circles[current.num]->radius;
					circles[parent]->isInSideCircle = true;
				}
			}
		}		
	}

	for(const auto& circle : circles) {
		bool isDivide = circle->radius == circle->inSideRadius;
		answer++;
		if (circle->isInSideCircle && isDivide)
			answer++;		
	}

	cout << answer;
	return 0;
}