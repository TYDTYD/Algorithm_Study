#include <iostream>
#include <vector>
#include <set>
using namespace std;

vector<int> graph[10001];
int disc[10001], low[10001];
bool visited[10001];
int timeCounter = 1;
set<int> answer;

void dfs(int u, int p) {
    visited[u] = true;
    disc[u] = low[u] = timeCounter++;

    int child = 0;

    for (int v : graph[u]) {
        if (p == v)
            continue;

        if (!visited[v]) {
            child++;
            dfs(v, u);
            low[u] = min(low[u], low[v]);

            if ((p==-1 && child>=2) || (p!=-1 && low[v] >= disc[u])) {
                answer.insert(u);
            }
        }
        else
            low[u] = min(low[u], disc[v]);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int v, e;
    cin >> v >> e;

    for (int i = 0; i < e; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    for (int i = 1; i <= v; i++) {
        if (!visited[i]) {
            dfs(i, -1);
        }
    }

    cout << answer.size() << '\n';
    for (const auto& ans : answer)
        cout << ans << ' ';

    return 0;
}
