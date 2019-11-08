// Задача №203. Мячик на лесенке
// https://informatics.mccme.ru/mod/statements/view3.php?chapterid=203

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.precision(20);
    int n;
    cin >> n;
    if (n == 1) {
        cout << "1\n";
        return 0;
    }
    vector<int> dp(n + 1);
    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 2;
    for (int i = 3; i <= n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3]; 
    }
    cout << dp[n] << '\n';
    return 0;
}
