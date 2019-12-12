// Задача №6. Дейкстра: восстановление пути
// https://informatics.mccme.ru/mod/statements/view3.php?chapterid=6

#include <bits/stdc++.h>
using namespace std;

#define ifthen(x, y, z) (x ? y: z)

const int INF = 2009000999;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.precision(20);
    int n, s, f;
    cin >> n >> s >> f;
    s--;
    f--;
    vector<vector<pair<int, int>>> graph(n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            int t;
            cin >> t;
            if (t > 0) {
                graph[i].emplace_back(j, t);
            }
        }
    }
    vector<int> dist(n, INF);
    vector<int> parent(n, -1);
    set<pair<int, int>> st; 
    dist[s] = 0;
    st.emplace(0, s);
    while (!st.empty()) {
        int min_idx = st.begin()->second;
        st.erase(st.begin());
        for (auto j : graph[min_idx]) {
            int u, w;
            tie(u, w) = j;
            if (dist[u] > dist[min_idx] + w) {
                st.erase({dist[u], u});
                dist[u] = dist[min_idx] + w;
                parent[u] = min_idx;
                st.emplace(dist[u], u);
            }
        }
    }
    if (dist[f] == INF) {
        cout << -1 << '\n';
    } else {
        vector<int> ans;
        int t = f;
        while (t != -1) {
            ans.push_back(t + 1);
            t = parent[t];
        }
        for (auto i = ans.rbegin(); i < ans.rend(); ++i) {
            cout << *i << ' ';
        }
        cout << '\n';
    }
    return 0;
}
