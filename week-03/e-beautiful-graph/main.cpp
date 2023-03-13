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
using Graph = unordered_map<int, unordered_set<int>>;
//endregion
std::unordered_map<int,size_t> BFS (const Graph & graph, int start, std::unordered_set<int> & visited) {
    std::unordered_map<int, size_t> distanceMap;
    queue<int> q;
    q.push(start);
    visited.insert(start);
    distanceMap[start] = 0;
    while (!q.empty()) {
        auto vertex = q.front();
        q.pop();
        if (!graph.contains(vertex)) continue;
        for (const auto &neighbour: graph.at(vertex)) {
            if (!visited.contains(neighbour)) {
                q.push(neighbour);
                visited.insert(neighbour);
                distanceMap[neighbour] = distanceMap[vertex] + 1;
            }
        }
    }
}
void runTask() {

    int t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        int result = 0;
        int vertexCount, edges;
        cin >> vertexCount >> edges;
        unordered_set<int> vertices(vertexCount);
        Graph graph;
        for (int j = 0; j < edges; ++j) {
            int from, to;
            cin >> from >> to;
            graph[from].emplace(to),graph[to].emplace(from);
            vertices.emplace(from);
            vertices.emplace(to);
        }
        unordered_set<int> visited;
        for (const auto &item: vertices) {
            if (!visited.contains(item)) {
                auto distanceMap = BFS(graph, item, visited);

                //todo: Finish implementing this bullshit:
//                Algoritmus Bipart
//                Vstup: Souvislý graf G = (V, E).
//                (1) Zvol libovolně počáteční vrchol v0.
//                (2) Pomocí BFS spočti vzdálenosti všech vrcholů od v0.
//                (3) Pro každou hranu {u, v} ověř, jestli d(v0, u)  != d(v0, v).
//                (4) Pokud existuje hrana {u, v} tak, že d(v0, u) = d(v0, v):
//                (5)       return Není bipartitní.
//                (6) Jinak return Je bipartitní.
// VIZ courses AG2 - přednáška 2

                //todo: If the component is not bipartite graph, dump it and cout << 0 << endl
                // If it is, and the graph is not connected (we have multiple bipartite components)
                // multiply the result from each component
                // result for each component can be obtained trivially, it's 2^k,
                // where k is the amount of vertices in the larger bipartite component,
                // we're counting subsets of k vertices, where each vertex can have number 1 or 3
                // if the components have same amount of vertices, then it's 2 * 2^k
            }
        }
    }
}