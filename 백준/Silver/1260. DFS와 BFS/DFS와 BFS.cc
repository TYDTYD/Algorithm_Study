#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

bool visited[1001];
vector<int> graph[1001];

void dfs(int x) {
    visited[x] = true;
    cout << x << ' ';
    for (int i = 0; i < graph[x].size(); i++) {
        int y = graph[x][i];
        if (!visited[y]) dfs(y);
    }
}

void bfs(int start) {
    queue<int> q;
    q.push(start);
    visited[start] = true;
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        cout << x << ' ';
        for (int i = 0; i < graph[x].size(); i++) {
            int y = graph[x][i];
            if (!visited[y]) {
                q.push(y);
                visited[y] = true;
            }
        }
    }
}

int main()
{
    int n, m, v;
    int node1, node2;
    cin >> n >> m >> v;

    for (int i = 0; i < m; i++) {
        cin >> node1 >> node2;
        graph[node1].push_back(node2);
        graph[node2].push_back(node1);
    }

    for (int i = 0; i <=1000; i++) {
        sort(graph[i].begin(), graph[i].end());
    }

    dfs(v);
    cout << endl;
    for (int i = 0; i <= 1000; i++) {
        visited[i] = false;
    }
    bfs(v);

    return 0;
}
