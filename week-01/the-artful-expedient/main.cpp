//region Template
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <set>
#include <map>
#include <vector>
#include <string>
#include <iostream>
#include <set>
#include <iostream>
#include <vector>
#include <variant>
#include <ctime>
#include <source_location>
#include <random>
#include <unordered_map>
#include <unordered_set>
#include <optional>
#include <memory>
#include <sstream>
#include <queue>
#include <ranges>
#include <span>
#include <algorithm>
#include <numeric>
#include <functional>
#include <bitset>
#include <array>
#include <concepts>
#include <iomanip>

#define STRINGIZE(x) #x
#define STRINGIZE_VALUE_OF(x) STRINGIZE(x)

using namespace std;

using ll = std::intmax_t;
using ld = long double;
using fast = std::int_fast32_t;
namespace rng = std::ranges;
#define int ll
//endregion
signed main() {
#ifdef MAIN_DIR_PATH
    freopen(STRINGIZE_VALUE_OF(MAIN_DIR_PATH)"/input", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll t, n, k;
    vector<ll> v1;
    set<ll> distinctNumbers;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        ll num;
        cin >> num;
        distinctNumbers.emplace(num);
    }
    int res = 0;
    for (const auto &item1: distinctNumbers) {
        for (const auto &item2: distinctNumbers) {
            if (distinctNumbers.count(item1^item2)) {
                res++;
            }
        }
    }
    if (res%2) {
        cout << "Koyomi";
    } else {
        cout << "Karen";
    }
    return 0;
}