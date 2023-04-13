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
    for (auto &item: dir) {
        if (item.path().has_filename()) {
            const auto &name = item.path().filename();
            if (!name.string().starts_with("input-")) continue;
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
}

#define OPEN_AND_RUN_INPUTS  openAndRunInputs();    \
}                                                   \
signed runTask() {

#else
#define OPEN_AND_RUN_INPUTS
#endif

//endregion

constexpr int SWAP = 1e12;
constexpr int REMOVE = (1e12 + 1);

signed main() {
OPEN_AND_RUN_INPUTS

    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        vector<bool> stringSeq;
        std::string sequence;
        size_t onesCount = 0;
        cin >> sequence;
        for (auto item: sequence) {
            item -= '0';
            stringSeq.push_back(item);
            if (item) onesCount++;
        }
        int result = 0;
        bool lookingFor = true;
        //if (onesCount > sequence.size() / 2) lookingFor = true;
        for (int j = stringSeq.size() - 1; j >= 0; --j) {
            if (stringSeq[j] != lookingFor) {
                int countOnes = 0;
                for (int l = j - 1; l >= 0; --l) {
                    if (stringSeq[l] == lookingFor) countOnes++;
                }
                if ((countOnes > 1 && stringSeq[j - 1] == lookingFor && stringSeq[j - 2] != lookingFor) ||
                    (countOnes == 1 && stringSeq[j - 1] == lookingFor)) {
                    result += SWAP;
                    result += REMOVE * (countOnes - 1);
                    break;
                } else {
                    result += REMOVE;
                }
            }
        }
        cout << result << endl;
    }


    return 0;
}
//endregion
