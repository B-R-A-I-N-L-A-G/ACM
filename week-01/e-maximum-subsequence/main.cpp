//region Template
#include <algorithm>
#include <array>
#include <bitset>
#include <concepts>
#include <ctime>
#include <functional>
#include <iomanip>
#include <iostream>
#include <iostream>
#include <map>
#include <memory>
#include <numeric>
#include <optional>
#include <queue>
#include <random>
#include <ranges>
#include <set>
#include <set>
#include <span>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <variant>
#include <vector>
#include <vector>

#define STRINGIZE(x) #x
#define STRINGIZE_VALUE_OF(x) STRINGIZE(x)

using namespace std;

using ll = std::intmax_t;
using ld = long double;
using fast = std::int_fast32_t;
namespace rng = std::ranges;
#define int ll
//endregion

vector<ll> get_all_sums(const vector<ll> &a, ll mod) {
    vector<ll> s;
    for (ll i = 0; i < (1 << a.size()); ++i) {
        ll sum = 0;
        for (ll j = 0; j < a.size(); ++j) {
            if (i & (1 << j)) {
                sum += a[j];
                sum %= mod;
            }
        }
        s.push_back(sum);
    }
    return s;
}


signed main() {
#ifdef MAIN_DIR_PATH
    freopen(STRINGIZE_VALUE_OF(MAIN_DIR_PATH)"/input", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll k, m;
    cin >> k >> m;
    vector<ll> a(k / 2);
    for (auto &e: a) cin >> e;
    vector<ll> b(k / 2 + k % 2);
    for (auto &e: b) cin >> e;

    auto s = get_all_sums(a, m);
    a.clear();

    auto t = get_all_sums(b, m);

    rng::sort(s);
    rng::sort(t);


    ll ans = 0;
    for (auto e: s) {
        auto it = rng::lower_bound(t, m - e);
        if (it != t.begin()) {
            ans = max(ans, (e + *(it - 1)) % m);
        }
        ans = max(ans, (e + t[0]) % m);
        ans = max(ans, (e + t[t.size() - 1]) % m);
    }
    cout << ans << endl;
    return 0;
}
