#include <iostream>
#include <string.h>
using namespace std;

int n, m, k;
int graph[101][101];

bool dfs(int x, int y) {
    if (x <= -1 || x >= n || y <= -1 || y >= m) {
        return false;
    }
    if (graph[x][y] == 1) {
        graph[x][y] = 0;
        dfs(x - 1, y);
        dfs(x, y - 1);
        dfs(x + 1, y);
        dfs(x, y + 1);
        return true;
    }
    return false;
}

int main()
{
    int T;
    int a, b;

    cin >> T;
    while (T > 0) {
        T--;
        int result = 0;
        cin >> n >> m >> k;

        memset(graph, 0, sizeof(graph));

        for (int i = 0; i < k; i++) {
            cin >> a >> b;
            graph[a][b] = 1;
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (dfs(i, j)) {
                    result+=1;
                }
            }
        }
        cout << result << endl;
    }
}