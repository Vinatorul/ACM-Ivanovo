// Задача №915. Платная лестница
// https://informatics.mccme.ru/mod/statements/view3.php?chapterid=915

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.precision(20);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &i : a)
        cin >> i;
    vector<int> dp(n);
    dp[0] = a[0];
    dp[1] = a[1];
    for (int i = 2; i < n; ++i) {
        dp[i] = min(dp[i - 1], dp[i - 2]) + a[i];
    }
    cout << dp[n - 1] << '\n';
    return 0;
}
