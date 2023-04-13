//region Template
#include <algorithm>
#include <array>
#include <bitset>
#include <concepts>
#include <ctime>
#include <functional>
#include <filesystem>
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
#include <regex>
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
template<typename T> using uset = unordered_set<T>;
template<typename K, typename V> using umap = unordered_map<K, V>;

#ifndef __APPLE__
namespace rng = std::ranges;
#endif

template<typename T>
ostream &operator<<(ostream &os, const vector<T> &v) {
    for (const auto &item: v) os << item << " ";
    return os;
}

template<typename T>
istream &operator>>(istream &is, vector<T> &v) {
    for (auto &item: v) is >> item;
    return is;
}

template<typename T, typename K>
ostream &operator<<(ostream &os, const pair<T, K> &p) {
    return os << p.first < " " << p.second;
}

template<typename T, typename K>
istream &operator>>(istream &is, pair<T, K> &p) { return is >> p.first >> p.second; }

#define int ll

//kubik

#ifdef MAIN_DIR_PATH
signed runTask();

void openAndRunInputs() {
    namespace fs = std::filesystem;

    auto dir = fs::directory_iterator(STRINGIZE_VALUE_OF(MAIN_DIR_PATH));
    vector<string> files;
    for (auto & item : dir) {
        if (item.path().has_filename()) {
            const auto & name = item.path().filename();
            if (!name.string().starts_with("input-")) continue;
            files.emplace_back(item.path().string());
        }
    }

    sort(files.begin(), files.end());
    for (string & file : files) {
        cout << "======================================================================" << endl;
        cout << "= Running input file " << file << endl;
        cout << "======================================================================" << endl;
        freopen(file.c_str(), "r", stdin);
        runTask();
    }
}

#define OPEN_AND_RUN_INPUTS  openAndRunInputs();    \
    }                                                   \
    signed runTask() {

#else
#define OPEN_AND_RUN_INPUTS
#endif

//endregion



signed main() {
OPEN_AND_RUN_INPUTS

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    size_t s, q;
    cin >> s >> q;

    int idx = 0;

    std::array lookup = {
            std::array { 4, 2, 7, 1 },
            std::array { 6, 3, 5, 0 },
            std::array { 5, 0, 6, 3 },
            std::array { 7, 1, 4, 2 },
            std::array { 0, 6, 3, 5 },
            std::array { 2, 7, 1, 4 },
            std::array { 1, 4, 2, 7 },
            std::array { 3, 5, 0, 6 },
    };

    std::array<std::function<size_t (size_t, size_t)>, 8> getIndex = {
            [s] (size_t x, size_t y) { return y * s + x; },
            [s] (size_t x, size_t y) { return (s - y - 1) * s + x; },
            [s] (size_t x, size_t y) { return y * s + (s - x - 1); },
            [s] (size_t x, size_t y) { return (s - y - 1) * s + (s - x - 1); },
            [s] (size_t x, size_t y) { return x * s + y; },
            [s] (size_t x, size_t y) { return x * s + (s - y - 1); },
            [s] (size_t x, size_t y) { return (s - x - 1) * s + y; },
            [s] (size_t x, size_t y) { return (s - x - 1) * s + (s - y - 1); }
    };

    for (size_t i = 0; i < q; ++i) {
        char m; cin >> m;
        if (m == 'q') {
            size_t x, y; cin >> x >> y;
            std::cout << getIndex[idx](y - 1, x - 1) + 1 << std::endl;
        } else {
            char c; cin >> c;
            idx = lookup[idx][c - 'a'];
        }
    }

    return 0;
}
//endregion