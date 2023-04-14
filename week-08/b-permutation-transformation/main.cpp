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


struct IndexedSizeT {
    size_t idx;
    size_t val;
};

using MaxLookup = vector<vector<IndexedSizeT>>;

MaxLookup buildMaxLookup (const vector<size_t> & p) {
    size_t levels = (sizeof(p.size()) * CHAR_BIT) - __builtin_clzll(p.size());
    MaxLookup lookup (levels);

    lookup[0].resize(p.size());
    for (size_t i = 0; i < p.size(); ++i) {
        lookup[0][i] = { .idx = i, .val = p[i] };
    }

    for (size_t i = 1; i < levels; ++i) {
        auto & currLevel = lookup[i];
        auto & prevLevel = lookup[i - 1];
        size_t blockSize = 1 << i;
        size_t levelSize = p.size() - blockSize + 1;

        currLevel.resize(levelSize);
        for (size_t j = 0; j < levelSize; ++j) {
            if (prevLevel[j].val > prevLevel[j + blockSize / 2].val) {
                currLevel[j] = prevLevel[j];
            } else {
                currLevel[j] = prevLevel[j + blockSize / 2];
            }
        }
    }

    return lookup;
}


size_t highestSmallerOrEqualPowerOf2 (size_t n) {
    return n == 0 ? 0 : 1 << ((sizeof(size_t) * CHAR_BIT) - __builtin_clzll(n));
}


IndexedSizeT findMaxIdx (const MaxLookup & lookup, size_t fromI, size_t toI) {
    size_t searchLen = toI - fromI + 1;
    size_t level = (sizeof(size_t) * CHAR_BIT) - __builtin_clzll(searchLen) - 1;
    size_t blockSize = 1 << level;

    if (lookup[level][fromI].val > lookup[level][toI - blockSize + 1].val) {
        return lookup[level][fromI];
    } else {
        return lookup[level][toI - blockSize + 1];
    }
}


struct Node {
    IndexedSizeT val;
    unique_ptr<Node> l = nullptr, r = nullptr;

    explicit Node(IndexedSizeT val):
    val(val) { }
};


unique_ptr<Node> buildTree (const MaxLookup & lookup, ssize_t fromI, ssize_t toI) {
    if (fromI > toI) return nullptr;

    if (fromI == toI) {
        return make_unique<Node>(lookup[0][fromI]);
    }

    IndexedSizeT max = findMaxIdx(lookup, fromI, toI);
    auto node = make_unique<Node>(max);
    node->l = buildTree(lookup, fromI, max.idx - 1);
    node->r = buildTree(lookup, max.idx + 1, toI);
    return node;
}


void populateDepths (const unique_ptr<Node> & node, vector<size_t> & depths, size_t depth = 0) {
    if (node == nullptr) return;
    depths[node->val.idx] = depth;
    populateDepths(node->l, depths, depth + 1);
    populateDepths(node->r, depths, depth + 1);
}


void test () {
    size_t N; cin >> N;
    vector<size_t> p (N, 0);
    for (auto & el : p) cin >> el;

    auto lookup = buildMaxLookup(p);
    auto tree = buildTree(lookup, 0, p.size() - 1);

    vector<size_t> depths (p.size(), 0);
    populateDepths(tree, depths);

    for (auto it = depths.begin(); it != depths.end(); ++it) {
        if (it != depths.begin()) cout << " ";
        cout << *it;
    }

    cout << endl;
}


signed main () {
    OPEN_AND_RUN_INPUTS

    ios::sync_with_stdio(false);
    cin.tie(0);

    size_t T; cin >> T;
    for (size_t i = 0; i < T; ++i) test();

    return 0;
}
//endregion
