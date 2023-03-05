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
ostream &operator<<(ostream &os, const pair<T, K> &p) {
    return os << p.first < " " << p.second;
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
}