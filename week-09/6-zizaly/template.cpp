#include <bits/stdc++.h>

using namespace std;

#define int long long
int gcd(int a, int b) {
    return b ? gcd(b, a % b) : a;
}
int countColorings(int n) {
    int res = 0;
    for (int i = 0; i < n; ++i) {
        res += pow(2, gcd(i, n));
    }
    res /= n;
    return res;
}
signed main() {
    int k;
    cin >> k;
    for (int i = 0; i < k; ++i) {
        int n;
        cin >> n;
        cout << countColorings(n) << endl;
    }
    return 0;
}