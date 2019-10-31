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
        int l = -1;
        int r = n;
        while (r - l > 1) {
            int m = (l + r) / 2;
            if (v[m] < t) {
                l = m;
            } else {
                r = m;
            }
        }
        int a = l;
        l = -1;
        r = n;
        while (r - l > 1) {
            int m = (l + r) / 2;
            if (v[m] <= t) {
                l = m;
            } else {
                r = m;
            }
        }
        int b = l;
        if (a == b) {
            cout << "0\n";
        } else {
            cout << a + 2 << " " << b + 1 << '\n';
        }
    }
    return 0;
}
