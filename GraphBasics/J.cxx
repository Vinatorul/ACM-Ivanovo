// Задача №165. Банкет
// https://informatics.mccme.ru/mod/statements/view3.php?chapterid=165

#include <bits/stdc++.h>
using namespace std;

#define ifthen(x, y, z) (x ? y: z)

const int INF = 1e9 + 1;
const long long INF64 = 1e18 + 1;
const double PI = acos(-1);

bool dfs(int v, int color, vector<vector<int>> &graph, vector<int> &colors) {
    colors[v] = color;
    for (int u : graph[v]) {
        if (colors[u] == color) {
            return false;
        }
        if (colors[u] == 0) {
            if (!dfs(u, color % 2 + 1, graph, colors)) {
                return false;
            }
        }
    }
    return true;
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
        graph[v].emplace_back(u);
    }
    bool bad_loop_found = false;
    vector<int> colors(n);
    for (int i = 0; i < n; ++i) {
        if (colors[i] == 0) {
            if (!dfs(i, 1, graph, colors)) {
                bad_loop_found = true;
                break;
            }
        }
    }
    if (bad_loop_found) {
        cout << "NO\n";
    } else {
        cout << "YES\n";
        for (int i = 0; i < n; ++i) {
            if (colors[i] == 1) {
                cout << i + 1 << " ";
            }
        }
    }
    cout << endl;
    return 0;
}
