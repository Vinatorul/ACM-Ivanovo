// Задача №164. Обход графа
// https://informatics.mccme.ru/mod/statements/view3.php?chapterid=164

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
    int n, s;
    cin >> n >> s;
    s--;
    vector<vector<int>> graph(n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            int t; 
            cin >> t;
            if (t == 1) {
                graph[i].emplace_back(j);
            }
        }
    }
    vector<int> used(n);
    dfs(s, graph, used);
    int ans = 0;
    for (auto &i : used) {
        if (i == 1)
            ans++;
    }
    cout << ans << '\n' << '\n';
    return 0;
}
