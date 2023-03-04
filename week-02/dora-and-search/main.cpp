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
template <typename T> using uset = unordered_set<T>;
template <typename K, typename V> using umap = unordered_map<K, V>;
namespace rng = std::ranges;
#define int ll

//kubik

//endregion

void solve() {
    int l; cin >> l;
    vector<int> nums(l);

    for (int j = 0; j < l; ++j) cin >> nums[j];

    int lowIdx = 0;
    int hiIdx = l - 1;

    int min = 1;
    int max = l;

    bool changed = true;
    while (changed) {
        changed = false;

        while (nums[lowIdx] == min || nums[lowIdx] == max) {
            if (nums[lowIdx] == min) min ++;
            else max--;

            lowIdx++;

            if (lowIdx > hiIdx) {
                cout << -1 << endl;
                return;
            }
        }

        while (nums[hiIdx] == min || nums[hiIdx] == max) {
            if (nums[hiIdx] == min) min ++;
            else max--;

            hiIdx--;
            changed = true;

            if (lowIdx > hiIdx) {
                cout << -1 << endl;
                return;
            }
        }
    }

    cout << lowIdx + 1 << " " << hiIdx + 1 << endl;
}

signed main() {
#ifdef MAIN_DIR_PATH
    freopen(STRINGIZE_VALUE_OF(MAIN_DIR_PATH)"/input", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;

    for (int i = 0; i < n; ++i) {
        solve();
    }

    return 0;
}
