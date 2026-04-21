#include <iostream>
#include <string>
#include <vector>
using namespace std;

int n, m, s;
string idx, id;
char graph[51][51];
int chance[1001];
bool visited[51][51];
pair<int, int> a=make_pair(0,0);


int main()
{
    cin >> n >> m >> s;
    pair<int, int> b = make_pair(n-1, m-1);

    for (int i = 0; i < n; i++) {
        cin >> idx;
        for (int j = 0; j < m; j++) {
            graph[i][j] = idx[j];
        }
    }

    cin >> id;
    int firstIdx,secondIdx;
    int count=100000;
    bool check = false;
    string answer;

    for (int i = 0; i < s; i++) {
        for (int j = 0; j < s; j++) {
            if (id[i] == id[j])
                chance[i] += 1;
        }
    }

    for (int i = 0; i < s; i++) {
        int cnt = 0;
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < m; k++) {
                if (id[i] == graph[j][k])
                    cnt++;
            }
        }
        if (count > cnt/chance[i]) {
            count = cnt/chance[i];
        }
    }

    for (int i = 0; i < count; i++) {
        for (int j = 0; j < s; j++) {
            firstIdx = a.first;
            secondIdx = a.second;
            for (int k = 0; k < n; k++) {
                if (check)
                    break;
                for (int l = 0; l < m; l++) {
                    if (!visited[k][l] && graph[k][l] == id[j]) {
                        visited[k][l] = true;
                        check = true;
                        a.first = k;
                        a.second = l;
                        break;
                    }
                }
            }
            if (a.first - firstIdx > 0)
                for (int i = 0; i < a.first - firstIdx; i++)
                    answer += 'D';
            else
                for (int i = 0; i < firstIdx - a.first; i++)
                    answer += 'U';
            if (a.second - secondIdx > 0)
                for (int i = 0; i < a.second - secondIdx; i++)
                    answer += 'R';
            else
                for (int i = 0; i < secondIdx - a.second; i++)
                    answer += 'L';
            answer += 'P';
            check = false;
        }
    }

    if (b.first - a.first > 0)
        for (int i = 0; i < b.first - a.first; i++)
            answer += 'D';
    if (b.second - a.second > 0)
        for (int i = 0; i < b.second - a.second; i++)
            answer += 'R';
    
    
    cout << count << " " << answer.length() << "\n";
    cout << answer;
}