// Задача №111728. Левый и правый двоичный поиск
// https://informatics.mccme.ru/mod/statements/view3.php?chapterid=111728

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<int> v(n);
    for (int &i : v)
        cin >> i;
    for (int i = 0; i < m; ++i) {
        int t;
        cin >> t;
        auto a = lower_bound(v.begin(), v.end(), t);
        auto b = upper_bound(v.begin(), v.end(), t);
        if (a == b) {
            cout << "0\n";
        } else {
            cout << a - v.begin() + 1 << " " << b - v.begin() << "\n";
        }
    }
    return 0;
}
