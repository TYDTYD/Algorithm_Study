#include <iostream>
#include <vector>
#include <algorithm>
typedef long long ll;
using namespace std;

int ccw(pair<ll, ll>& a, pair<ll, ll>& b, pair<ll, ll>& c) {
    ll s = (a.first - b.first) * (c.second - b.second) - (a.second - b.second) * (c.first - b.first);
    if (s > 0) 
        return 1;
    else if (s == 0) 
        return 0;
    else 
        return -1;
}

ll intersect(pair<pair<ll, ll>, pair<ll, ll>>& x, pair<pair<ll, ll>, pair<ll, ll >>& y) {
    pair<ll, ll> a = x.first;
    pair<ll, ll> b = x.second;
    pair<ll, ll> c = y.first;
    pair<ll, ll> d = y.second;
    if (ccw(a, b, c) * ccw(a, b, d) == 0 && ccw(c, d, a) * ccw(c, d, b) == 0) {
        if (a > b) swap(a, b);
        if (c > d) swap(c, d);
        return c <= b && a <= d;
    }
    return (ccw(a, b, c) * ccw(a, b, d) <= 0 && ccw(c, d, a) * ccw(c, d, b) <= 0);
}

struct cut {
    int id;
    pair<pair<ll, ll>, pair<ll, ll>> p;
    ll w;
    cut(ll _id=0,ll s1 = 0, ll s2 = 0, ll e1 = 0, ll e2 = 0, ll _w = 0) {
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
    bool used[2501] = {};
    cut arr[2501];
    cin >> n;

    for (int i = 0; i < n; i++) {
        arr[i].id = i;
        cin >> arr[i].p.first.first >> arr[i].p.first.second >> arr[i].p.second.first >> arr[i].p.second.second;
        cin >> arr[i].w;
    }

    sort(arr, arr + n, sort_w);

    for (int i = 0; i < n; i++) {
        used[arr[i].id] = true;
        ll m = 0;
        for (int j = i + 1; j < n; j++) {
            if (intersect(arr[i].p, arr[j].p))
                m++;
        }
        answer += arr[i].w * (m + 1);
    }

    cout << answer;
	return 0;
}