#include <iostream>
using namespace std;

int n;
int answer = 0;
bool visited1[50];
bool visited2[50];
bool visited3[50];

void solve(int count) {
    if (count == n) {
        answer++;
        return;
    }
    
    for (int i = 0; i < n; i++) {
        if (!visited1[i] && !visited2[i+count] && !visited3[count-i+n-1]) {
            visited1[i] = 1;
            visited2[i + count] = 1;
            visited3[count - i + n - 1] = 1;
            solve(count+1);
            visited1[i] = 0;
            visited2[i + count] = 0;
            visited3[count - i + n - 1] = 0;
        }
    }
}

int main()
{
    cin >> n;
    solve(0);

    cout << answer;
}