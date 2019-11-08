// Задача №2968. Калькулятор с восстановлением ответа
// https://informatics.mccme.ru/mod/statements/view3.php?chapterid=2968

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.precision(20);
    int n;
    cin >> n;
    vector<int> dp(n + 1);
    vector<int> p(n + 1);
    dp[1] = 0;
    p[1] = -1;
    for (int i = 2; i <= n; ++i) {
        dp[i] = dp[i - 1] + 1;
        p[i] = 1;
        if (i % 2 == 0) {
            if (dp[i / 2] < dp[i]) {
                dp[i] = dp[i / 2] + 1;
                p[i] = 2;
            }
        }
        if (i % 3 == 0) {
            if (dp[i / 3] < dp[i]) {
                dp[i] = dp[i / 3] + 1;
                p[i] = 3;
            }
        }
    }
    vector<int> ans;
    int t = n;
    while (p[t] > 0) {
        if (p[t] == 1) {
            t = t - 1;
            ans.push_back(1);
        } else if (p[t] == 2) {
            t = t / 2;
            ans.push_back(2);
        } else {
            t = t / 3;
            ans.push_back(3);
        }
    }
    cout << dp[n] << "\n";
    for (int i = ans.size() - 1; i >= 0; --i) {
        cout << ans[i];
    }
    cout << '\n';
    return 0;
}
