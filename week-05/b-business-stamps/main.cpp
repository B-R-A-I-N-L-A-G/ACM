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


struct RatedPoint {
    int row, col, r;
};

bool operator < (const RatedPoint & a, const RatedPoint & b) {
    return a.r > b.r;
}


signed main() {
    OPEN_AND_RUN_INPUTS

    ios::sync_with_stdio(false);
    cin.tie(0);

    int N, M; cin >> N >> M;
    vector<vector<int>> map (N, vector<int>(M));

    int HR, HC; cin >> HR >> HC;
    int TR, TC; cin >> TR >> TC;

    for (auto & row : map) {
        for (auto & pos : row) {
            cin >> pos;
        }
    }

    vector<vector<unordered_set<int>>> places (N, vector<unordered_set<int>>(M));
    places[HR][HC].insert(map[HR][HC]);

    priority_queue<RatedPoint> q;
    q.push({ HR - 1, HC - 1, 1 });

    while (!q.empty()) {
        RatedPoint currPoint = q.top();
        q.pop();

        for (auto [drow, dcol] : { pair { -1, 0 }, { 1, 0 }, { 0, 1 }, { 0, -1 } }) {
            int row = currPoint.row + drow, col = currPoint.col + dcol;
            if (row < 0 || row >= N || col < 0 || col >= M) continue;

            int newCount = places[currPoint.row][currPoint.col].count(map[row][col]) ? currPoint.r : currPoint.r + 1;
            if (!places[row][col].empty() && newCount >= places[row][col].size()) continue;

            places[row][col] = places[currPoint.row][currPoint.col];
            places[row][col].insert(map[row][col]);

            q.push({ row, col, newCount });
        }
    }

    cout << places[TR - 1][TC - 1].size() << endl;
    return 0;
}
//endregion
