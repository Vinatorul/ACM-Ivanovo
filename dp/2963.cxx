// Задача №2963. Калькулятор
// https://informatics.mccme.ru/mod/statements/view3.php?chapterid=2963

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.precision(20);
    int n;
    cin >> n;
    vector<int> dp(n + 1);
    dp[1] = 0;
    for (int i = 2; i <= n; ++i) {
        dp[i] = dp[i - 1] + 1;
        if (i % 2 == 0) {
            if (dp[i / 2] < dp[i]) {
                dp[i] = dp[i / 2] + 1;
            }
        }
        if (i % 3 == 0) {
            if (dp[i / 3] < dp[i]) {
                dp[i] = dp[i / 3] + 1;
            }
        }
    }
    cout << dp[n] << "\n";
    return 0;
}
