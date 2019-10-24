// Задача №166. Построение
// https://informatics.mccme.ru/mod/statements/view3.php?chapterid=166

#include <bits/stdc++.h>
using namespace std;

#define ifthen(x, y, z) (x ? y: z)

const int INF = 1e9 + 1;
const long long INF64 = 1e18 + 1;
const double PI = acos(-1);

bool dfs(int v, vector<vector<int>> &graph, 
         vector<int> &colors, vector<int> &top) {
    colors[v] = 1;
    for (int u : graph[v]) {
        if (colors[u] == 1) {
            return true;
        }
        if (colors[u] == 0) {
            if (dfs(u, graph, colors, top)) {
                return true;
            }
        }
    }
    colors[v] = 2;
    top.emplace_back(v);
    return false;
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
        u--;
        v--;
        graph[u].emplace_back(v);
    }
    bool loop_found = false;
    vector<int> colors(n);
    vector<int> top;
    for (int i = 0; i < n; ++i) {
        if (colors[i] == 0) {
            if (dfs(i, graph, colors, top)) {
                loop_found = true;
                break;
            }
        }
    }
    if (loop_found) {
        cout << "No\n\n";
    } else {
        cout << "Yes\n";
        for (int i = top.size() - 1; i >= 0; --i) {
            cout << top[i] + 1 << " ";
        }
    }
    return 0;
}
