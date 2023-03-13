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
std::pair<std::unordered_map<int,size_t>, std::unordered_map<int, unordered_set<int>>> BFS (const Graph & graph, int start, std::unordered_set<int> & visited) {
    std::unordered_map<int, size_t> distanceMap;
    std::unordered_map<int, unordered_set<int>> edgesUsed;

    queue<int> q;
    q.push(start);
    visited.insert(start);
    distanceMap[start] = 0;
    while (!q.empty()) {
        auto vertex = q.front();
        q.pop();
        if (!graph.contains(vertex)) continue;
        for (const auto &neighbour: graph.at(vertex)) {
            edgesUsed[vertex].insert(neighbour);
            edgesUsed[neighbour].insert(vertex);
            if (!visited.contains(neighbour)) {
                q.push(neighbour);
                visited.insert(neighbour);
                distanceMap[neighbour] = distanceMap[vertex] + 1;
            }
        }
    }
    return {distanceMap, edgesUsed};
}
int fast_power(int number, int power) {
    if (power == 1) {
        return number;
    }
    if (power % 2 == 1) {
        return number * fast_power(number, power - 1)%998244353;
    }
    int powah = fast_power(number, power / 2)%998244353;
    return (powah * powah)%998244353;
}
void runTask() {

    int t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        int result = 1;
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
                auto [distanceMap, edgesUsed] = BFS(graph, item, visited);
                for (const auto &[from, edgesSet] : edgesUsed) {
                    for (const auto &to: edgesSet) {
                        if (distanceMap[from] == distanceMap[to] && from != to) {
                            cout << 0 << endl;
                            goto end;
                        }
                    }
                }
                int c1 = 0, c2 = 0;
                for (const auto &[vertex, distance]: distanceMap) {
                    if (distance%2) c2++;
                    else c1++;
                }
                result *= (fast_power(2,c1) + fast_power(2, c2))%998244353;
                result %= 998244353;
            }
        }
        if (vertices.size() < (size_t)vertexCount) {
            result *= fast_power(3, vertexCount-vertices.size())%998244353;
            result %= 998244353;
        }
        cout << result << endl;
        end:;
    }
}