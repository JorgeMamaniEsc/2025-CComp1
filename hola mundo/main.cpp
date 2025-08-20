#include <bits/stdc++.h>
using namespace std;

#define L 6
#define S 10

int cnt[L + 1][S + 1], val[S + 1];
bool inv[S + 1];

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        string num;
        cin >> num;
        inv[num[0] - 'a'] = true;
        int sz = num.size();
        for (int j = 0; j < sz; j++) {
            cnt[L - sz + j][num[j] - 'a']++;
        }
    }
    string alp = "abcdefghij";
    int ans = INT_MAX;
    do {
        if (inv[alp[0] - 'a']) continue;
        int p = 0;
        for (char c: alp) val[c - 'a'] = p++;
        int sum = 0, car = 0, pow = 1;
        for (int i = L - 1; i >= 0; i--) {
            int ac = 0;
            for (int j = 0; j < S; j++) {
                ac += cnt[i][j] * val[j];
            }
            ac += car;
            sum += pow * (ac % 10);
            pow *= 10;
            car = ac / 10;
        }
        while (car) {
            sum += pow * (car % 10);
            pow *= 10;
            car /= 10;
        }
        ans = min(ans, sum);
    } while (next_permutation(alp.begin(), alp.end()));
    cout << ans << endl;
}
