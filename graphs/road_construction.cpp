#include <bits/stdc++.h>
using namespace std;

class Disjoint_set {
public:
    vector<int> par;
    vector<int> size;
    int components;
    int max_size;
    
    Disjoint_set(int n) {
        par.resize(n+1);
        iota(par.begin(), par.end(), 0); // parent[i] = i
        size.assign(n+1, 1);
        components = n;
        max_size = 1;
    }
    
    int find_set(int n) {
        if (par[n] != n) {
            par[n] = find_set(par[n]);
        }
        return par[n];
    }
    
    void unions(int u, int v) {
        int ku = find_set(u);
        int kv = find_set(v);
        if (ku == kv) return; // already same set
        
        if (size[ku] >= size[kv]) {
            par[kv] = ku;
            size[ku] += size[kv];
            max_size = max(max_size, size[ku]);
        } else {
            par[ku] = kv;
            size[kv] += size[ku];
            max_size = max(max_size, size[kv]);
        }
        components--;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    Disjoint_set ds(n);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        ds.unions(a, b);
        cout << ds.components << " " << ds.max_size << "\n";
    }
}
