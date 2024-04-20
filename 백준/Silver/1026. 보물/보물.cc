#include <iostream>
#include <algorithm>
using namespace std;

bool compare(int a, int b)
{
    if (a > b)
        return 1;
    else
        return 0;
}

int main()
{
    int n;
    int result = 0;
    cin >> n;
    int a[50];
    int b[50];

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int j = 0; j < n; j++) {
        cin >> b[j];
    }
    sort(a, a + n);
    sort(b, b + n, compare);

    for (int k = 0; k < n; k++) {
        result += a[k] * b[k];
    }

    cout << result;
}