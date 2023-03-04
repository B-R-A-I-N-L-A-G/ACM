//region Template
#include <algorithm>
#include <array>
#include <bitset>
#include <concepts>
#include <ctime>
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

//endregion
signed main() {
#ifdef MAIN_DIR_PATH
    freopen(STRINGIZE_VALUE_OF(MAIN_DIR_PATH)"/input", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);

    int x;
    cin >> x;

    for(int p = 0; p < x; ++p) {
        std::string l;
        cin >> l;
        vector<char> mins(l.size() + 1);
        mins[l.size()] = l[l.size()-1];
        for(int b = l.size()-1;b >= 0 ; --b){
            mins[b] = min(l[b],mins[b+1]);
        }

        vector<int> chars(10);
        vector<pair<char,int>> to_replace;
        for(int b = 0; b < l.size(); ++b) {
            if(l[b] > mins[b]) {
                chars[min((l[b]-'0')+1,9)]++;
            } else {
                chars[(l[b]-'0')]++;
            }
        }
        for(int index = 0; index < 10;index++){
            for(int count = 0; count < chars[index]; count++) {
                cout << (char)((char)'0' + index);
            }
        }
        cout << endl;
    }

    return 0;
}
