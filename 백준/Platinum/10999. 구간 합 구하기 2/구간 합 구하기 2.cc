#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

void init(vector<long long>& num, vector<long long>& tree, int node, int start, int end) {
    if (start == end) {
        tree[node] = num[start];
    }
    else {
        init(num, tree, node * 2, start, (start + end) / 2);
        init(num, tree, node * 2 + 1, (start + end) / 2 + 1, end);
        tree[node] = tree[node * 2] + tree[node * 2 + 1];
    }
}

void updateLazy(int start, int end, int idx, vector<long long>& tree, vector<long long>& lazy) {
    if (lazy[idx] != 0) {
        tree[idx] += (end - start + 1) * lazy[idx];
        if (start != end) {
            lazy[idx * 2] += lazy[idx];
            lazy[idx * 2 + 1] += lazy[idx];
        }
        lazy[idx] = 0;
    }
}

void updateRange(vector<long long>& tree, vector<long long>& lazy, int node, int start, int end, int left, int right, long long val) {
    updateLazy(start, end, node, tree, lazy);
    if (right < start || left > end) {
        return;
    }

    // 범위 안에 전부 들어간다면... lazy에 넣고 tree에 그대로 넣고 끝낸다
    if (left <= start && right >= end) {
        tree[node] += (end - start + 1) * val;
        if (start != end) {
            lazy[node * 2] += val;
            lazy[node * 2 + 1] += val;
        }
        return;
    }
    // 범위 안에 일부가 걸친다면... 두 갈래로 갈라야 겠구나
    updateRange(tree, lazy, node * 2, start, (start + end) / 2, left, right, val);
    updateRange(tree, lazy, node * 2 + 1, (start + end) / 2 + 1, end, left, right, val);
    tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

long long search(vector<long long>& tree, vector<long long>& lazy, int node, int start, int end, int left, int right) {
    updateLazy(start, end, node, tree, lazy);
    if (left > end || right < start) {
        // 범위를 벗어났다면 0 리턴
        return 0;
    }
    if (left <= start && end <= right) {
        // 범위 안에 있다면 그 범위의 합 리턴
        return tree[node];
    }
    long long lsum = search(tree, lazy, node * 2, start, (start + end) / 2, left, right);
    long long rsum = search(tree, lazy, node * 2 + 1, (start + end) / 2 + 1, end, left, right);
    return lsum + rsum;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, m, k;
    cin >> n >> m >> k;
    
    vector<long long> number(n);
    int h = (int)ceil(log2(n));
    int tree_size = (1 << (h + 1));
    vector<long long> tree(tree_size), lazy(tree_size);
    m += k;

    for (int i = 0; i < n; i++)
        cin >> number[i];

    init(number, tree, 1, 0, n - 1);
    
    while (m--) {
        int query;
        cin >> query;
        if (query == 1) {
            int left, right;
            long long val;
            cin >> left >> right >> val;
            updateRange(tree, lazy, 1, 0, n - 1, left - 1, right - 1, val);
        }
        else {
            int left, right;
            cin >> left >> right;
            cout << search(tree, lazy, 1, 0, n - 1, left - 1, right - 1) << '\n';
        }
    }
    
    return 0;
}