#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

bool CheckMove(int r, int c, int n, vector<vector<int>>& map) {
	if (r < 0 || r >= n || c < 0 || c >= n)
		return false;
	if (map[r][c] == 1)
		return false;
	return true;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m, r, c;
	r = c = 0;
	cin >> n >> m;
	vector<vector<int>> map(n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int x;
			cin >> x;
			map[i].push_back(x);
			if (x == 2) {
				r = i;
				c = j;
			}
		}
	}
	char keyboard[4] = {'W', 'A', 'S', 'D'};
	vector<pair<int, int>> directions = { {-1, 0}, {0, -1}, {1, 0}, {0, 1} };
	unordered_map<char, int> directionIndex;
	unordered_map<char, pair<int, int>> moveDirections;	
	unordered_map<char, string> commands;	
	for (int i = 0; i < 4; i++) {
		string command;
		cin >> command;
		commands[keyboard[i]] = command;
		moveDirections[keyboard[i]] = directions[i];
		directionIndex[keyboard[i]] = i;
	}

	string pressed_keys;
	cin >> pressed_keys;

	bool downTriggered = false;
	bool upTriggered[4] = { false, false, false, false };
	bool stayTriggered = false;

	char before_key = '\0';

	for (int i = 0; i < pressed_keys.size(); i++) {
		char key = pressed_keys[i];
		if (before_key == key)
			stayTriggered = true;
		else
			stayTriggered = false;
		if (before_key != key)
			downTriggered = true;
		else
			downTriggered = false;
		for (int j = 0; j < 4; j++) {
			if (upTriggered[j] && commands[keyboard[j]] == "Up") {
				int posX = r + moveDirections[keyboard[j]].first;
				int posY = c + moveDirections[keyboard[j]].second;
				if (CheckMove(posX, posY, n, map)) {
					r = posX;
					c = posY;
				}
				continue;
			}
			if (key == keyboard[j]) {
				int posX = r + directions[j].first;
				int posY = c + directions[j].second;
				if (downTriggered && commands[key] == "Down") {
					if (CheckMove(posX, posY, n, map)) {
						r = posX;
						c = posY;
					}
				}
				if (stayTriggered && commands[key] == "Stay") {
					if (CheckMove(posX, posY, n, map)) {
						r = posX;
						c = posY;
					}
				}
			}
		}
		before_key = key;
		for (int j = 0; j < 4; j++)
			upTriggered[j] = false;
		if (i + 1 < pressed_keys.size() && pressed_keys[i + 1] != key)
			upTriggered[directionIndex[key]] = true;
	}

	for(int i = 0; i<4; i++)
		if (upTriggered[i]) {
			int posX = r + moveDirections[keyboard[i]].first;
			int posY = c + moveDirections[keyboard[i]].second;
			if (CheckMove(posX, posY, n, map)) {
				r = posX;
				c = posY;
			}
		}

	cout << r + 1 << ' ' << c + 1;
	return 0;
}