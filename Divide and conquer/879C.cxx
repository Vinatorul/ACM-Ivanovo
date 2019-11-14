// C. Загадка Нефлены
// https://codeforces.com/problemset/problem/897/C

#include <bits/stdc++.h>
using namespace std;

#define ifthen(x, y, z) (x ? y: z)

const int INF = 1e9 + 1;
const long long INF64 = 1e18 + 1;
const double PI = acos(-1);

string f0 = "What are you doing at the end of the world? Are you busy? Will you save us?";
string s1 = "What are you doing while sending \"";
string s2 = "\"? Are you busy? Will you send \"";
string s3 = "\"?";

char get_ans(const int n, const long long k, const vector<long long> &lens) {
    if (n == 0) {
        if (k < f0.size()) {
            return f0[k];
        } else {
            return '.';
        }
    }
    long long tmp_k = k;
    if (tmp_k < s1.size()) {
        return s1[tmp_k];
    }
    tmp_k -= s1.size();
    if (tmp_k < lens[n - 1]) {
        return get_ans(n - 1, tmp_k, lens);
    }
    tmp_k -= lens[n - 1];
    if (tmp_k < s2.size()) {
        return s2[tmp_k];
    }
    tmp_k -= s2.size();
    if (tmp_k < lens[n - 1]) {
        return get_ans(n - 1, tmp_k, lens);
    }
    tmp_k -= lens[n - 1];
    if (tmp_k < s3.size()) {
        return s3[tmp_k];
    }
    return '.';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.precision(20);
    vector<long long> lens(100001);
    lens[0] = f0.size();
    for (int i = 1; i < lens.size(); ++i) {
        long long tmp = s1.size() + lens[i - 1] + s2.size() + lens[i - 1] + s3.size();
        lens[i] = min((long long)1e18 + 1, tmp);
    }
    int q;
    cin >> q;
    while (q --> 0) {
        int n;
        long long k;
        cin >> n >> k;
        k--;
        cout << get_ans(n, k, lens);
    }
    cout << endl;
    return 0;
}
