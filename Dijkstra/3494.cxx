// Задача №3494. Алгоритм Дейкстры за MlogN 
// https://informatics.mccme.ru/mod/statements/view3.php?chapterid=3494

#include <bits/stdc++.h>
using namespace std;

#define ifthen(x, y, z) (x ? y: z)

const int INF = 2009000999;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.precision(20);
    int q;
    cin >> q;
    while (q --> 0) {
        int n, m;
        cin >> n >> m;
        vector<vector<pair<int, int>>> graph(n);
        for (int i = 0; i < m; ++i) {
            int u, v, w;
            cin >> u >> v >> w;
            graph[u].emplace_back(v, w);
            graph[v].emplace_back(u, w);
        }
        vector<int> dist(n, INF);
        int s;
        cin >> s;
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
                    st.emplace(dist[u], u);
                }
            }
        }
        for (int i : dist) {
            cout << i << ' ';
        }
        cout << '\n';
    }
    return 0;
}
