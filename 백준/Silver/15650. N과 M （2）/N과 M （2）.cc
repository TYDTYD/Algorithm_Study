#include <iostream>
using namespace std;

int n, m;
int arr[10];
bool isUsed[10];

void Backtracking(int k,int start) {
    if (k == m) {
        for (int i = 0; i < m; i++) {
            cout << arr[i] << ' ';
        }
        cout << '\n';
        return;
    }

    for (int i = start; i <= n; i++) {
        if (!isUsed[i]) {
            arr[k] = i;
            isUsed[i] = 1;
            Backtracking(k + 1,i+1);
            isUsed[i] = 0;
        }
    }
}

int main()
{
    cin >> n >> m;

    Backtracking(0,1);
}