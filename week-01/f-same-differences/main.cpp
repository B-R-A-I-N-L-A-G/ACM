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

#define STRINGIZE(x) #x
#define STRINGIZE_VALUE_OF(x) STRINGIZE(x)

using namespace std;

using ll = std::intmax_t;
using ld = long double;
using fast = std::int_fast32_t;
namespace rng = std::ranges;
#define int ll
//endregion
signed main() {
#ifdef MAIN_DIR_PATH
    freopen(STRINGIZE_VALUE_OF(MAIN_DIR_PATH)"/input", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        ll count;
        ll lmao = 0;
        cin >> count;
        unordered_map<ll,ll> v1;
        for (int j = 0; j < count; ++j) {
            ll num;
            cin >> num;
            v1[num-j] ++;
        }
        for(auto&  [x,y] : v1)
        {
            if (y >= 2) {
                lmao += (y*(y-1)) /2;
            }
        }
        cout << lmao << endl;
    }
    return 0;
}
