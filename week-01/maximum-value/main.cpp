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

    ll _;
    cin >> _;

    vector<ll> s;
    copy(istream_iterator<ll>(cin), istream_iterator<ll>(), back_inserter(s));

    rng::sort(s);

    ll currMax = 0;

    for (fast i = 0; i < s.size(); i++) {
        if (i && s[i - 1] == s[i]) continue;
        bool failed = false;
        for (fast k = 2; !failed; k++) {
            auto possible = rng::lower_bound(s, (s[i] * k));
            failed = possible == s.end();
            if (possible == s.begin()) continue;
            currMax = max(currMax, *(possible - 1) % s[i]);
        }
    }
    cout << currMax << endl;
    return 0;
}