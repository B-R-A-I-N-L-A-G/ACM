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

namespace std {
template <typename A, typename B>
struct hash<pair<A, B>> {
    size_t operator () (const pair<A, B> & p) const {
        return hash<A>()(p.first) ^ (hash<B>()(p.second) << 1);
    }
};
}

//kubik

//endregion

bool solve() {
    int n; cin >> n;
    string a, b;
    cin >> a >> b;

    umap<pair<char, char>, int> charMap;
    for (int i = 0; i < n; ++i) {
        auto p = pair { a[i], b[n - i - 1] };
        if (p.first > p.second) swap(p.first, p.second);
        charMap[p] += 1;
    }

    optional<pair<char, char>> oddPair = nullopt;
    for (auto [p, count] : charMap) {
        if (count % 2) {
            if (oddPair) return false;
            if (p.first != p.second) return false;
            oddPair = p;
        }
    }

    return true;
}

signed main() {
#ifdef MAIN_DIR_PATH
    freopen(STRINGIZE_VALUE_OF(MAIN_DIR_PATH)"/input", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;
    for (int i = 0; i < n; ++i) {
        cout << (solve() ? "YES" : "NO") << endl;
    }

    return 0;
}
