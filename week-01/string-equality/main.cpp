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

    ll count = 'z' - 'a' + 1;

    ll _;
    cin >> _;
    ll n, k;
    string a, b;
    while (cin >> n >> k >> a >> b) {
        vector<ll> from(count + 1);
        vector<ll> to(count + 1);

        for (auto c: a)
            from[c - 'a']++;
        for (auto c: b)
            to[c - 'a']++;

        bool failed = false;
        for (fast i = 0; i < count && !failed; i++) {
            if (from[i] < to[i] || (from[i] - to[i]) % k) failed = true;
//            cout << "Letter: "<< (char)('a' + i)  << " "<< from[i] << " " << to[i] << " "<< failed<<  endl;
            from[i] -= to[i]; // Sub the letters we need
            from[i + 1] += from[i]; // transform to next letter
            from[i] = 0;
        }
        cout << (failed ? "No" : "Yes") << endl;
    }
    return 0;
}