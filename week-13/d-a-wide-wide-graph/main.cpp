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

int deepest_node(const umap<int, vector<int>> &tree, int start) {
    vector<bool> visited(tree.size() + 1, false);

    queue<int> Q;

    Q.push(start);

    int node = start;
    while(!Q.empty()) {
        node = Q.front();
        Q.pop();
        visited[node] = true;

        for(auto neigh: tree.at(node)) {
            if(visited[neigh])
                continue;
            Q.push(neigh);
        }
    }
    return node;
}

void get_dist(const umap<int, vector<int>> &tree,
              vector<int> &dist,
              int s0) {
    fill(all(dist), -1);
    dist[s0] = 0;

    queue<int> Q;
    Q.push(s0);
    while(!Q.empty()) {
        int node = Q.front();
        Q.pop();

        for(auto neigh: tree.at(node)) {
            if(dist[neigh] >= 0)
                continue;
            Q.push(neigh);
            dist[neigh] = dist[node] + 1;
        }
    }
}

void solve() {
    umap<int, vector<int>> tree;

    int n;
    cin >> n;

    for(int i = 1; i < n; i++) {
        int a, b = 0;
        cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }

    int deepest = deepest_node(tree, 1);
    int deep = deepest_node(tree, deepest);

    vector<int> d0(n+1);
    vector<int> d1(n+1);

    get_dist(tree, d0, deepest);
    get_dist(tree, d1, deep);

    int last = 0;
    vector<int> at_dist(n+2, 0);
    for(int i = 1; i < (int)d0.size(); i++) {
        int m = max(d0[i], d1[i]);
        at_dist[m]++;
        last = max(m, last);
    }

    int comp = 1;
    for(int k = 1; k <= n; k++) {
        comp += at_dist[k-1];
        cout << comp << (k == n ? "" : " ");
        comp -= last == k;
    }

    cout << endl;
}

signed main() {
    OPEN_AND_RUN_INPUTS

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tc = 1;
    // cin >> tc;
    for (int t = 1; t <= tc; t++) {
        solve();
    }
    return 0;
}
//endregion
