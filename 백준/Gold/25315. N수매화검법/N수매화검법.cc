#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;

int ccw(pll& p1, pll& p2, pll& p3) {
    ll s = p1.first * p2.second + p2.first * p3.second + p3.first * p1.second;
    s -= (p1.second * p2.first + p2.second * p3.first + p3.second * p1.first);
    if (s > 0)
        return 1;
    else if (s == 0)
        return 0;
    else
        return -1;
}

ll intersect(pair <pll, pll> &x, pair<pll, pll>& y) {
    pll a = x.first, b = x.second, c = y.first, d = y.second;
    return ccw(a, b, c) * ccw(a, b, d) <= 0 && ccw(c, d, a) * ccw(c, d, b) <= 0;
}

struct cut {
    int id;
    pair<pll, pll> p;
    ll w;
    cut(int _id = 0, int s1 = 0, int s2 = 0, int e1 = 0, int e2 = 0, int _w = 0) {
        id = _id;
        p.first.first = s1;
        p.first.second = s2;
        p.second.first = e1;
        p.second.second = e2;
        w = _w;
    }
};

bool sort_w(cut& a, cut& b) {
    return a.w < b.w;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    int n;
    ll answer = 0;
    vector<int> num[2501] = {};
    cut arr[2501];
    cin >> n;

    for (int i = 0; i < n; i++)
        cin >> arr[i].p.first.first >> arr[i].p.first.second >> arr[i].p.second.first >> arr[i].p.second.second >> arr[i].w;

    sort(arr, arr + n, sort_w);

    for (int i = 0; i < n; i++) {
        int m = 0;
        for (int j = i + 1; j < n; j++) {
            if (intersect(arr[i].p, arr[j].p))
                m++;
        }
        answer += arr[i].w * (m + 1);
    }

    cout << answer;
    return 0;
}