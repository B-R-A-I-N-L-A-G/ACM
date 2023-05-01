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

using Graph = vector<vector<int>>;
//endregion
struct CTree {
    struct CNode {
        CNode(int index, CNode * parent)
                : m_Index(index), m_Parent(parent) {}
        int m_Index;
        CNode * m_Parent;
        vector<CNode *> m_Children;
    };

    CTree (const Graph & adj_list, int root_index) : m_Root(new CNode(root_index, nullptr)) {
        construct_tree_from_adj_list(m_Root, adj_list);
    }
    ~CTree () {
        delete_node(m_Root);
    }
    void delete_node (CNode * ptr) {
        for (const auto &item: ptr->m_Children) {
            delete_node(item);
        }
        delete ptr;
    }
    void construct_tree_from_adj_list(CNode * ptr,const Graph & adj_list) {
        for (const auto item: adj_list[ptr->m_Index]) {
            if (item == ptr->m_Index) continue;
            auto child = new CNode(item, ptr);
            m_Root->m_Children.push_back(child);
            construct_tree_from_adj_list(child, adj_list);
        }
    }
    int lca (CNode * u, CNode * v) {
        while (u != v) {
            if (m_Levels[u->m_Index] > m_Levels[v->m_Index]) {
                u = u->m_Parent;
            } else {
                v = v->m_Parent;
            }
        }
        return u->m_Index;
    }
    void dfs (CNode * node, int level) {
        m_Levels[node->m_Index] = level;
        for (const auto &item: node->m_Children) {
            dfs(item, level+1);
        }
    }
    vector<int> m_Levels;
    CNode * m_Root;
};
signed main() {
    OPEN_AND_RUN_INPUTS

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int vertices;
    cin >> vertices;
    Graph adj_list;
    for (int i = 0; i < (vertices - 1); ++i) {
        int u, v;
        cin >> u >> v;
        adj_list[u].push_back(v), adj_list[v].push_back(u);
    }
    CTree tree (adj_list, 1);
    int queries;
    cin >> queries;
    for (int i = 0; i < queries; ++i) {

    }
    return 0;
}
//endregion
