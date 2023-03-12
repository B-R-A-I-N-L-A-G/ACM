//region Template
#include <algorithm>
#include <array>
#include <bitset>
#include <concepts>
#include <ctime>
#include <filesystem>
#include <functional>
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
template <typename T> using uset = unordered_set<T>;
template <typename K, typename V> using umap = unordered_map<K, V>;
namespace rng = std::ranges;
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


void printState(const vector<int> & v) {
    int coord = 1;
    for (int pos : v) {
        while (coord < pos) {
            cout << ' ';
            ++coord;
        }

        if (coord == pos) {
            cout << 'x';
            ++coord;
        }
    }

    cout << endl;
}


void printEndState(const vector<int> & curr) {
    cout << "End coords:";
    int count = 0;

    for (size_t i = 0; i < curr.size(); ++i) {
        if (i > 0 && curr[i] == curr[i - 1]) continue;
        cout << " " << (double)curr[i] / 2.0;
        count += 1;
    }
    cout << "  |  distinct: " << count << endl;
}


bool shouldMove(const vector<int> & curr, size_t j) {
    bool move = true;
    if (j > 0 && curr[j] == curr[j - 1]) move = false;
    if (j < curr.size() - 1 && curr[j] == curr[j + 1]) move = false;
    return move;
}


pair<int, int> findBestMove(const vector<int> & curr, size_t j) {
    pair<int, int> bestMove = { 0, numeric_limits<int>::max() };
    if (j > 0) {
        int dist = curr[j] - curr[j - 1];
        bestMove = { -1, dist };
    }

    if (j < curr.size() - 1) {
        int dist = curr[j + 1] - curr[j];
        if (dist < bestMove.second) {
            bestMove = { 1, dist };
        }
    }

    return bestMove;
}


void moveStone(const vector<int> & curr, vector<int> & next, size_t j, pair<int, int> bestMove, bool & moved) {
    if (bestMove.first == 0) return;
    moved = true;

    if (abs(curr[j] - curr[j + bestMove.first]) <= 2) {
        next[j] += bestMove.first;
    } else {
        next[j] += bestMove.first * 2;
    }
}


void simulate(const vector<int> & v) {
    set<int> endCoords;

    for (int i = ((1 << v.size()) - 1); i > 0; --i) {
        vector<int> curr;
        for (size_t j = 0; j < v.size(); ++j) {
            if (i & (1 << j)) curr.push_back(v[j] * 2);
        }

        if (curr.size() < 2) continue;

        printState(curr);

        bool moved = true;
        vector<int> next = curr;
        while (moved) {
            moved = false;

            for (size_t j = 0; j < curr.size(); ++j) {
                next[j] = curr[j];
                if (!shouldMove(curr, j)) continue;
                pair<int, int> bestMove = findBestMove(curr, j);
                moveStone(curr, next, j, bestMove, moved);
            }

            swap(curr, next);
            printState(curr);
        }

        for (int pos : curr) endCoords.insert(pos);
        printEndState(curr);
        cout << endl << endl;
    }

    cout << endl << "All end coords:";
    for (int coord : endCoords) cout << " " << coord;
    cout << "  |  distinct: " << endCoords.size() << endl;
}


vector<int> randomInput(size_t count, int maxCoord) {
    set<int> s;
    while (s.size() < count) s.insert((random() % maxCoord) + 1);
    return { s.begin(), s.end() };
}


signed main() {
    OPEN_AND_RUN_INPUTS

    ios::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; ++i) cin >> v[i];
//    vector<int> v = randomInput(10, 50);
    simulate(v);

    return 0;
}
