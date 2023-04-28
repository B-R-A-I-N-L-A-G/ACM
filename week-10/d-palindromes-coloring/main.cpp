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

#define ALPHABET_LEN ('z' - 'a' + 1)


int longest_palindrome(const string &s, int k) {
    int counts[ALPHABET_LEN] = {0,};
    for(const auto c: s) counts[c-'a']++;

    int pair_count = 0, unpaired_cnt = 0;

    for (const auto &item: counts) {
        pair_count += item / 2;
        unpaired_cnt += item % 2;
    }

    int base = pair_count / k;
    unpaired_cnt += 2 * (pair_count % k);
    return base * 2 + (unpaired_cnt >= k);
}


signed main() {
    OPEN_AND_RUN_INPUTS

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        int n, k;
        cin >> n >> k;
        string sequence;
        cin >> sequence;
        cout << longest_palindrome(sequence, k) << endl;
    }

    return 0;
}
//endregion
