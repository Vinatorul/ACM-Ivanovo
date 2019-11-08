// Задача №843. Простая последовательность
// https://informatics.mccme.ru/mod/statements/view3.php?chapterid=843

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.precision(20);
    int n; 
    cin >> n;
    vector<int> dp(n + 1);
    dp[0] = 1;
    dp[1] = 1;
    for (int i = 2; i <= n; i++) {
        if (i % 2) { // число нечётное
            dp[i] = dp[i / 2] - dp [i / 2 - 1];
        } else { // число чётное
            dp[i] = dp[i / 2] + dp[i / 2 - 1];
        }
    }
    cout << dp[n] << "\n";
    return 0;
}
