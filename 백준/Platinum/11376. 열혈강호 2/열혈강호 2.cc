#include <iostream>
#include <vector>
using namespace std;

int n, m;
vector<int> jobs[2001];
int assign[1001];
bool done[1001];

bool dfs(int x) {
    for (int i = 0; i < jobs[x].size(); i++) {
        int job = jobs[x][i];
        if (done[job]) 
            continue;
        done[job] = true;
        if (assign[job] == 0 || dfs(assign[job])) {
            assign[job] = x;			
            return true;
        }
    }
    return false;
}

int match() {
    int ans = 0;
    for (int i = 1; i <= 2 * n; i++) {
        fill(done, done + 1001, false);
        if (dfs(i))
            ans++;
    }
    return ans;
}

int main() {
    cin >> n >> m;

    for (int i = 1; i <= n; ++i) {
        int k; 
        cin >> k;

        vector<int> temp;
        for (int j = 0; j < k; j++) {
            int job;
            cin >> job;
			temp.push_back(job);
        }
        for(int job : temp) {
            jobs[2 * i - 1].push_back(job);
            jobs[2 * i].push_back(job);
		}
    }
    cout << match();
	return 0;
}