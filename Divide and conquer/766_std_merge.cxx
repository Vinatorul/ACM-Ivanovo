// Задача №766. Сортировка слиянием
// https://informatics.mccme.ru/mod/statements/view3.php?chapterid=766

#include <bits/stdc++.h>
using namespace std;

#define ifthen(x, y, z) (x ? y: z)

const int INF = 1e9 + 1;
const long long INF64 = 1e18 + 1;
const double PI = acos(-1);

vector<int> merge_sort(vector<int> &v, int l, int r) {
    if (r - l == 1) {
        return {v[l]};
    }
    int m = (l + r) / 2;
    vector<int> left = merge_sort(v, l, m);
    vector<int> right = merge_sort(v, m, r);
    vector<int> result(r - l);
    merge(left.begin(), left.end(), right.begin(), right.end(), result.begin());
    return result;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.precision(20);
    int n;
    cin >> n;
    vector<int> v(n);
    for (int &i : v) {
        cin >> i;
    }
    vector<int> v_sorted = merge_sort(v, 0, n);
    for (int &i : v_sorted)
        cout << i << " ";
    cout << "\n";
    return 0;
}
