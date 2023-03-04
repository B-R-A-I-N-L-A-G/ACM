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
#include <list>

#define STRINGIZE(x) #x
#define STRINGIZE_VALUE_OF(x) STRINGIZE(x)

using namespace std;

using ll = std::intmax_t;
using ld = long double;
using fast = std::int_fast32_t;
namespace rng = std::ranges;
#define int ll

ld calc_dist(ld mid, const vector<ll> &pos, const vector<ll> &time_to_dress) {
    ld dist = 0;
    for (int i = 0; i < pos.size(); ++i) {
        dist = std::max(dist, abs(pos[i] - mid) + time_to_dress[i]);
    }
    return dist;
}

//endregion
signed main() {
#ifdef MAIN_DIR_PATH
    freopen(STRINGIZE_VALUE_OF(MAIN_DIR_PATH)"/input", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    fast test;
    cin >> test;
    for (fast i = 0; i < test; ++i) {
        fast n;
        cin >> n;
        vector<ll> pos(n);
        vector<ll> time_to_dress(n);
        ll max = numeric_limits<ll>::min();
        ll min = numeric_limits<ll>::max();
        for (fast j = 0; j < n; ++j) {
            cin >> pos[j];
            min = std::min(min, pos[j]);
            max = std::max(max, pos[j]);
        }
        for (fast j = 0; j < n; ++j) {
            cin >> time_to_dress[j];
        }

        ld left = min;
        ld distance_left = calc_dist(min, pos, time_to_dress);
        ld right = max;
        ld distance_right = calc_dist(max, pos, time_to_dress);

        while (abs(left - right) > 10e-8) {
            ld mid = abs(left + right) / 2;
            ld distance_mid = calc_dist(mid, pos, time_to_dress);
            if (distance_left > distance_right) {
                left = mid - 10e-9;
                distance_left = distance_mid;
            } else {
                right = mid + 10e-9;
                distance_right = distance_mid;
            }
        }
        cout << fixed << setprecision(10) << left << endl;
    }
    return 0;
}
