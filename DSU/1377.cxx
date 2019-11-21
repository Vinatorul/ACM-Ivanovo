// Задача №1377 Остовное дерево
// https://informatics.mccme.ru/mod/statements/view3.php?chapterid=1377

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
    set<tuple<int, int, int>> st;
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        u--; 
        v--;
        st.emplace(w, u, v);
    }
    int c = 0;
    long long ans = 0;
    while (c < n - 1) {
        int u, v, w;
        tie(w, u, v) = *st.begin();
        st.erase(st.begin());
        if (unite(u, v, p)) {
            ans = ans + w;
            c++;
        }
    }
    cout << ans << '\n';
    return 0;
}
