#include <bits/stdc++.h>
using namespace std;

#define ifthen(x, y, z) (x ? y: z)

void dfs(int v, vector<vector<int>> &graph, vector<int> &used) {
    used[v] = 1;
    for (int &u : graph[v]) {
        if (used[u] == 1)
            continue;
        dfs(u, graph, used); 
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.precision(20);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> graph(n);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        graph[u].emplace_back(v);
        graph[v].emplace_back(u);
    }
    vector<int> used(n);
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        if (used[i] == 0 && graph[i].size() > 0) {
            dfs(i, graph, used);
            ans++;
        }
    }
    cout << ans << '\n' << '\n';
    return 0;
}
