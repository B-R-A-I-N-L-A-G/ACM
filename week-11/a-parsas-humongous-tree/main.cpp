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


template<typename T, typename K>
ostream &operator<<(ostream &os, const pair<T, K> &p) {
    return os << p.first < " " << p.second;
}
template<typename T>
ostream &operator<<(ostream &os, const vector<T> &v) {
    for (const auto &item: v) os << item << " ";
    return os;
}
template<typename T, typename K>
istream &operator>>(istream &is, pair<T, K> &p) { return is >> p.first >> p.second; }

template<typename T>
istream &operator>>(istream &is, vector<T> &v) {
    for (auto &item: v) is >> item;
    return is;
}



#define int ll
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef pair<int, int> pii;
typedef vector<int> vi;
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
        cin.clear();
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

int maxDFS(const vector<vector<int>> &adj_list,
           const vector<pair<int, int>> &intervals,
           vector<pair<int, int>> &memoization,
           int parent, int current, bool is_max) {
    auto &memb = memoization[current];

    auto &cached = is_max ? memb.second : memb.first;
    if(cached != -1) return cached;

    auto &interval = intervals[current-1];
    int value = is_max ? interval.second : interval.first;

    int prettiness = 0;
    for(auto son: adj_list[current]) {
        if(son == parent) continue;
        prettiness += max(
                    maxDFS(adj_list, intervals, memoization, current, son, false) +
                        abs(intervals[son-1].first - value),
                    maxDFS(adj_list, intervals, memoization, current, son, true) +
                        abs(intervals[son-1].second - value)
                );
    }

    cached = prettiness;
    return prettiness;
}

void solve() {
    int vertices;
    cin >> vertices;
    vector<pair<int, int>> intervals(vertices);
    cin >> intervals;
    vector<vector<int>> adj_list(vertices + 1);
    for (int i = 0; i < (vertices - 1); ++i) {
        int u, v;
        cin >> u >> v;
        adj_list[u].push_back(v), adj_list[v].push_back(u);
    }

    vector<pair<int, int>> memoization(vertices + 1);
    for(auto &memb: memoization) {
        memb = {-1, -1};
    }

    cout << max(maxDFS(adj_list, intervals, memoization, 0, 1, false),
               maxDFS(adj_list, intervals, memoization, 0, 1, true)) << endl;
}

signed main() {
    OPEN_AND_RUN_INPUTS

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        solve();
    }
    return 0;
}
//endregion
