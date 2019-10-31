// Задача №4. Двоичный поиск
// https://informatics.mccme.ru/mod/statements/view3.php?chapterid=4

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.precision(20);
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for (auto &i : v)
        cin >> i;
    for (int i = 0; i < k; ++i) {
        int t;
        cin >> t;
        if (binary_search(v.begin(), v.end(), t)) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    return 0;
}
