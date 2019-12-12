// Задача №5. Дейкстра
// https://informatics.mccme.ru/mod/statements/view3.php?chapterid=5

#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.precision(20);
    int n, s, f;
    cin >> n >> s >> f;
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
    vector<int> used(n);
    vector<int> dist(n, INF);
    dist[s - 1] = 0;
    for (int i = 0; i < n; ++i) {
        int min_idx = -1;
        for (int j = 0; j < n; ++j) {
            if (used[j]) {
                continue;
            }
            if (min_idx == -1 || dist[min_idx] > dist[j]) {
                min_idx = j;
            }
        }
        if (dist[min_idx] == INF) {
            break;
        }
        used[min_idx] = 1;
        for (auto j : graph[min_idx]) {
            int u, w;
            tie(u, w) = j;
            if (used[u]) {
                continue;
            }
            if (dist[u] > dist[min_idx] + w) {
                dist[u] = dist[min_idx] + w;
            }
        }
    }
    if (dist[f - 1] == INF) {
        cout << -1 << '\n';
    } else {
        cout << dist[f - 1] << '\n';
    }
    return 0;
}
