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
namespace rng = std::ranges;

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
istream &operator>>(istream &is, pair<T, K> &p) { return is >> p.first >> p.second; }

#define int ll

bool runInDebug();

void runTask();

#ifdef MAIN_DIR_PATH

bool runInDebug() {
    namespace fs = std::filesystem;
    auto inputRegex = regex("input-\\d{2}");

    auto dir = fs::directory_iterator(STRINGIZE_VALUE_OF(MAIN_DIR_PATH));
    vector<string> files;
    for (auto &item: dir) {
        if (item.path().has_filename()) {
            const auto &name = item.path().filename();
            if (!regex_match(name.string(), inputRegex)) continue;
            files.emplace_back(item.path().string());
        }
    }

    sort(files.begin(), files.end());
    for (string &file: files) {
        cout << "======================================================================" << endl;
        cout << "= Running input file " << file << endl;
        cout << "======================================================================" << endl;
        freopen(file.c_str(), "r", stdin);
        runTask();
    }
    return true;
}

#else
bool runInDebug(){
    return false;
}
#endif

signed main() {
    if (runInDebug())
        return 0;

    ios::sync_with_stdio(false);
    cin.tie(0);
    runTask();
    return 0;
}
//endregion

void runTask() {
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> b(n);
    cin >> a >> b;
    umap<int, int> a_map;
    umap<int, int> b_map;
    for (int i = 0; i < n; ++i) {
        a_map[a[i]] = i;
        b_map[b[i]] = i;
    }

    int left = min(a_map[1], b_map[1]);
    int right = max(a_map[1], b_map[1]);

    int ans = (left * (left + 1)) / 2 +
              ((n - right - 1) * (n - right)) / 2 +
              max((int) 0, ((right - left - 1) * (right - left)) / 2);

    for (int i = 2; i <= n; ++i) {
        //          *- left
        //          |   *- right  *- local_right
        //  X X X X 1 X X X X X X 2
        //  X X X X X X 1 X X 2 X X
        //                    ^- local_left
        int local_left = min(a_map[i], b_map[i]);
        int local_right = max(a_map[i], b_map[i]);
        if (local_left >= right) {
            ans += (local_left - right) * (left + 1);
        }
        if (local_right <= left) {
            ans += (left - local_right) * (n - right);
        }
        if (local_left < left && local_right > right) {
            ans += (local_left - left) * (right - local_right);
        }
        left = min(left, local_left);
        right = max(right, local_right);
    }
    cout << ans + 1 << endl;
}