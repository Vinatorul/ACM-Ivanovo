// Задача №1375. Острова
// https://informatics.mccme.ru/mod/statements/view3.php?chapterid=1375

#include <bits/stdc++.h>
using namespace std;

int find_set(int u, vector<int> &p) {
    if (u == p[u]) {
        return u;
    }
    // return p[u] = find_set(p[u], p);
    int v =  find_set(p[u], p);
    p[u] = v;
    return v;
}

bool unite(int u, int v, vector<int> &p) {
    u = find_set(u, p);
    v = find_set(v, p);
    if (u == v) {
        return false;
    }
    if (rand() % 2) {
        p[v] = u;
    } else {
        p[u] = v;
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.precision(20);
    int n, m; 
    cin >> n >> m;
    vector<int> p(n);
    for (int i = 0; i < n; ++i) {
        p[i] = i;
    }   
    int last_unite = -1;
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        u--; 
        v--;
        if (unite(u, v, p)) {
            last_unite = i;
        }
    }
    cout << last_unite + 1 << '\n'2;
    return 0;
}
