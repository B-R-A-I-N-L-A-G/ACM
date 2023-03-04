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

    int n, _;
    cin >> _;
    string str;

    while (cin >> _ >> n >> str) {
        int result = 0, min = n;
        for (int i = 0; i < n; i++)
            if (str[i] == 'W') result++;
        if (result < min) min = result;
        for (int i = n; i < str.size(); ++i) {
            if (str[i] == 'W') result++;

            if (str[i - n] == 'W') result--;


            if (result < min) min = result;
        }
        std::cout << min << std::endl;
    }
    return 0;
}
