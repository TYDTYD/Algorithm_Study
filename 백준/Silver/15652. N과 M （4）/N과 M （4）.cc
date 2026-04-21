#include <iostream>
using namespace std;

int n, m;
int arr[10];

void Backtracking(int k,int count) {
    if (count == m) {
        for (int i = 0; i < m; i++) {
            cout << arr[i] << ' ';
        }
        cout << '\n';
        return;
    }

    for (int i = k; i <= n; i++) {
        arr[count] = i;
        Backtracking(i, count + 1);
    }
}

int main()
{
    cin >> n >> m;

    Backtracking(1,0);
}