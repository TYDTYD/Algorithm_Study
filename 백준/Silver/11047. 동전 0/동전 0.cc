#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> coin;
    int n, k, value;
    int index;
    int answer;
    answer = 0;
    cin >> n >> k;

    for (int i = 0; i < n; i++) {
        cin >> value;
        coin.push_back(value);
    }
    for (int j = 0; j < n; j++) {
        index = coin.back();
        if (index <= k) {
            answer = answer + (k / index);
            k = k - ((k / index)*index);
        }
        coin.pop_back();
    }
    cout << answer;

    return 0;
}