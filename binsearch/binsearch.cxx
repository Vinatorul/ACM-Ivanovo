// Задача №4. Двоичный поиск
// https://informatics.mccme.ru/mod/statements/view3.php?chapterid=4

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for (auto &i : v)
        cin >> i;
    for (int i = 0; i < k; ++i) {
        int t;
        cin >> t;
        int l = 0;
        int r = n;
        while (r - l > 1) {
            int m = (l + r) / 2;
            if (v[m] <= t) {
                l = m;
            } else {
                r = m;
            }
        }
        if (v[l] == t) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    return 0;
}
