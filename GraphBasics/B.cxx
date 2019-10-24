// Задача №98. Есть ли цикл?
// https://informatics.mccme.ru/mod/statements/view3.php?chapterid=98

#include <bits/stdc++.h>
using namespace std;

#define ifthen(x, y, z) (x ? y: z)

const int INF = 1e9 + 1;
const long long INF64 = 1e18 + 1;
const double PI = acos(-1);

bool dfs(int v, vector<vector<int>> &graph, vector<int> &colors) {
    colors[v] = 1; // зелёный
    for (int &u : graph[v]) {
        if (colors[u] == 1) {
            return true;
        } else if (colors[u] == 0) {
            if (dfs(u, graph, colors)) {
                return true;
            }
        }
    }
    colors[v] = 2; // красный
    return false;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.precision(20);
    int n;
    cin >> n;
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
    vector<int> colors(n);
    for (int i = 0; i < n; ++i) {
        if (colors[i] == 0) {
            if (dfs(i, graph, colors)) {
                cout << "1\n\n";
                return 0;
            }
        }
    }
    cout << "0\n\n";
    return 0;
}
