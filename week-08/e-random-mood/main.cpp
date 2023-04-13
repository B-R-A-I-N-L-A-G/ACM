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

std::vector<int> factorials = {1, 1, 2, 6, 24, 120};

int wrapper(int n, int k) {
    if(n <k)return factorials[n];
    return factorials[n] = n * wrapper(n - 1,k);
}

int factorial(int n) {
    if ((int) factorials.size() > n) {
        return factorials[n];
    } else {
        auto l = factorials.size();
        factorials.resize(n+1);
        return wrapper(n,l);
    }
}
int binom (int n, int k) {
    return factorial(n)/ (factorial(n-k)* factorial(k));
}

double super_smart_algo(int n, int k, double p, int s, int r) {
    int a = 1;
    int l = 1;

    double res = 1;

    while(a <= n){

        if(s--) {
            res *= p;
        }
        if(r--) {
            res *= 1-p;
        }
        res *= a++;

        if(l <= k) {
            res /= l++;
        }
    }
    res /= factorial(n-k);
    return res;
}

long double fast_power(long double number, int power) {
    if (power == 0) {
        return 1;
    }
    if (power == 1) {
        return number;
    }
    if (power % 2 == 1) {
        return number * fast_power(number, power - 1);
    }
    long double powah = fast_power(number, power / 2);
    return (powah * powah);
}
signed main() {
OPEN_AND_RUN_INPUTS

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int seconds;
    double prob;
    cin >> seconds >> prob;
    if (seconds == 1) {
        cout << setprecision(10) << (1 - prob) << endl;
        return 0;
    }
    long double res = 0;
    for (int i = 0; i <= seconds; i+=2) {
        res += super_smart_algo(seconds, i,prob,i, seconds-i);
//        res += fast_power((1-prob),seconds-i) * binom(seconds, i) * fast_power(prob,i);
    }
    cout << setprecision(10) << res << endl;
    return 0;
}
//endregion
