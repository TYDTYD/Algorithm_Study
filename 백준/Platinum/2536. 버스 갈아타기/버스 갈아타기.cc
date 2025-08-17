#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
using namespace std;

struct Point {
	int x, y;
	Point(int x = 0, int y = 0) : x(x), y(y) {}
};

struct BusLine {
	int number = 0;
	Point start, end;
};

bool isIntersect(Point A_Start, Point A_End, Point B_Start, Point B_End) {
	int typeA, typeB;
	if (A_Start.x == A_End.x)
		typeA = 0;
	else
		typeA = 1;
	if (B_Start.x == B_End.x)
		typeB = 0;
	else
		typeB = 1;

	if (typeA == typeB) {
		if (typeA == 0) {
			if(A_Start.x != B_Start.x)
				return false;
			if (A_Start.y > B_End.y || A_End.y < B_Start.y)
				return false;
			return true;
		}
		if (typeA == 1) {
			if(A_Start.y != B_Start.y)
				return false;
			if (A_Start.x > B_End.x || A_End.x < B_Start.x)
				return false;
			return true;
		}
	}
	else {
		if (typeA == 0) {
			if (A_Start.x >= B_Start.x && A_Start.x <= B_End.x && B_Start.y >= A_Start.y && B_Start.y <= A_End.y)
				return true;
		}
		else {
			if (B_Start.x >= A_Start.x && B_Start.x <= A_End.x && A_Start.y >= B_Start.y && A_Start.y <= B_End.y)
				return true;
		}
	}
	return false;
}

bool isContain(Point x, BusLine line) {
	if (line.start.x == line.end.x) {
		if (x.x != line.start.x)
			return false;
		if (x.y < line.start.y || x.y > line.end.y)
			return false;
		return true;
	}
	else {
		if (x.y != line.start.y)
			return false;
		if (x.x < line.start.x || x.x > line.end.x)
			return false;
		return true;
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int m, n;
	cin >> m >> n;
	int k;
	cin >> k;
	vector<BusLine> busLines(k + 1);
	for (int i = 0; i < k; i++) {
		int b, x1, y1, x2, y2;
		cin >> b >> x1 >> y1 >> x2 >> y2;
		if (x1 > x2)
			swap(x1, x2);
		if (y1 > y2)
			swap(y1, y2);
		busLines[b] = BusLine{ b, Point(x1, y1), Point(x2, y2) };
	}
	Point start, end;
	cin >> start.x >> start.y >> end.x >> end.y;

	int startParent, endParent;
	startParent = endParent = 0;
	unordered_set<int> startSet, endSet;

	for (int i = 0; i < k; i++) {
		if (isContain(start, busLines[i + 1]))
			startSet.insert(busLines[i + 1].number);		
		if (isContain(end, busLines[i + 1]))
			endSet.insert(busLines[i + 1].number);
	}

	queue<pair<int,int>> q;
	bool visited[5001] = {};
	int answer = -1;
	for (const auto& start : startSet) {
		q.push({ start, 1 });
		visited[start] = true;
	}
		
	while (!q.empty()) {
		pair<int,int> cur = q.front();
		q.pop();

		if (endSet.find(cur.first) != endSet.end()) {
			answer = cur.second;
			break;
		}

		for (auto& edge : busLines) {
			if (edge.number == cur.first)
				continue;
			if (visited[edge.number])
				continue;
			if (!isIntersect(busLines[cur.first].start, busLines[cur.first].end, busLines[edge.number].start, busLines[edge.number].end))
				continue;
			visited[edge.number] = true;
			q.push({ edge.number, cur.second + 1 });
		}
	}
	
	cout << answer;
	return 0;
}