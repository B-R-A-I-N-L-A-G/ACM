//region Template
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <set>
#include <map>
#include <vector>
#include <string>
#include <iostream>
#include <set>
#include <iostream>
#include <vector>
#include <variant>
#include <ctime>
#include <source_location>
#include <random>
#include <unordered_map>
#include <unordered_set>
#include <optional>
#include <memory>
#include <sstream>
#include <queue>
#include <ranges>
#include <span>
#include <algorithm>
#include <numeric>
#include <functional>
#include <bitset>
#include <array>
#include <concepts>
#include <iomanip>
#include <list>

#define STRINGIZE(x) #x
#define STRINGIZE_VALUE_OF(x) STRINGIZE(x)

using namespace std;

using ll = int;
using ld = long double;
using fast = std::int_fast32_t;
namespace rng = std::ranges;
#define int ll

//endregion

template<typename T>
struct rotating_vector {
    using value_type = T;
    using reference = T &;
    using const_reference = const T &;
    using pointer = T *;
    using const_pointer = const T *;
    using size_type = size_t;

    T *data;
    int capacity = 0;

    int offset = 0;
    int size = 0;

    void push_back(T t) {
        if (size == capacity) {
            if (capacity == 0) {
                capacity = 100;
                data = new T[capacity];
            } else {
                T *new_data = new T[capacity * 2 + 100];
                for (int i = 0; i < size; ++i) {
                    new_data[(offset + i) % (capacity * 2 + 100)] = std::move(data[(offset + i) % capacity]);
                }
                delete[] data;
                data = new_data;
                capacity *= 2;
                capacity += 100;
            }
        }
        data[(offset + size) % capacity] = t;
        ++size;
    }

    void pop_front() {
        ++offset;
        --size;
        offset %= capacity;
    }

    reference front() const {
        return data[offset];
    }

    bool empty() const {
        return size == 0;
    }

    template<typename ...Args>
    void emplace_back(Args &&... args) {
        push_back(T(std::forward<Args>(args)...));
    }
};


signed main() {
#ifdef MAIN_DIR_PATH
    freopen(STRINGIZE_VALUE_OF(MAIN_DIR_PATH)"/input", "r", stdin);
#endif

    int n;
    cin >> n;

    vector<int> max_jumps(n + 1), slip(n + 1);

    for (fast i = 1; i <= n; ++i) cin >> max_jumps[i];
    for (fast i = 1; i <= n; ++i) cin >> slip[i];

    vector<int> jumps(n + 1), falls(n + 1);

    queue<int, rotating_vector<int>> q;
    q.emplace(n);

    while (!q.empty()) {
        auto current = q.front();
        q.pop();

        for (int i = max_jumps[current]; i >= 1; --i) {
            int jump_without_slip = current - i;
            int next = jump_without_slip + slip[jump_without_slip];

            if (next == 0) {
                q = {};
                max_jumps = {};
                slip = {};
                std::vector<int> nums;
                nums.reserve(n + 1);
                nums.push_back(0);

                while (current != n) {
                    int before_fall = falls[current];
                    nums.push_back(before_fall);
                    int before_jump = jumps[before_fall];
                    current = before_jump;
                }
                cout << nums.size() << endl;
                for (auto it: rng::reverse_view(nums)) {
                    cout << it;
                    if (it) cout << " ";
                }
                cout << endl;
                return 0;
            }

            if (next >= n || falls[next] != 0 || jumps[jump_without_slip]) continue;

            jumps[jump_without_slip] = current;
            falls[next] = jump_without_slip;
            q.push(next);
        }
    }

    cout << -1 << endl;
}