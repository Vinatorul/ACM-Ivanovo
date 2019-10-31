// Задача №1923. Дипломы
// https://informatics.mccme.ru/mod/statements/view3.php?chapterid=1966

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int w, h, n;
    cin >> w >> h >> n;
    long long l, r;
    l = 0;
    r = 1ll * max(w, h) * n;
    while (r - l > 1) {
        long long m = (l + r) / 2;
        if ((m / w) * (m / h) >= n) {
            r = m;
        } else {
            l = m;
        }
    }
    cout << r << '\n';
    return 0;
}
