cmake_minimum_required(VERSION 3.23)
project(ACM)

set(CMAKE_CXX_STANDARD 20)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -pedantic")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -D DEBUG -D LOCAL -D _GLIBCXX_DEBUG -D _GLIBCXX_DEBUG_PEDANTIC -D _FORTIFY_SOURCE=2")
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=address -fsanitize=undefined -fno-sanitize-recover=all -fstack-protector")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fstack-clash-protection -fstack-protector-all")

project(week-01-a-black-and-white-stripe)
add_executable(week-01-a-black-and-white-stripe week-01/a-black-and-white-stripe/main.cpp)
target_compile_options(week-01-a-black-and-white-stripe PRIVATE -DMAIN_DIR_PATH=${CMAKE_CURRENT_SOURCE_DIR}/week-01/a-black-and-white-stripe)


project(week-01-b-everyone-is-a-winner)
add_executable(week-01-b-everyone-is-a-winner week-01/b-everyone-is-a-winner/main.cpp)
target_compile_options(week-01-b-everyone-is-a-winner PRIVATE -DMAIN_DIR_PATH=${CMAKE_CURRENT_SOURCE_DIR}/week-01/b-everyone-is-a-winner)


project(week-01-c-frog-traveler)
add_executable(week-01-c-frog-traveler week-01/c-frog-traveler/main.cpp)
target_compile_options(week-01-c-frog-traveler PRIVATE -DMAIN_DIR_PATH=${CMAKE_CURRENT_SOURCE_DIR}/week-01/c-frog-traveler)


project(week-01-d-the-artful-expedient)
add_executable(week-01-d-the-artful-expedient week-01/d-the-artful-expedient/main.cpp)
target_compile_options(week-01-d-the-artful-expedient PRIVATE -DMAIN_DIR_PATH=${CMAKE_CURRENT_SOURCE_DIR}/week-01/d-the-artful-expedient)


project(week-01-e-maximum-subsequence)
add_executable(week-01-e-maximum-subsequence week-01/e-maximum-subsequence/main.cpp)
target_compile_options(week-01-e-maximum-subsequence PRIVATE -DMAIN_DIR_PATH=${CMAKE_CURRENT_SOURCE_DIR}/week-01/e-maximum-subsequence)


project(week-01-f-same-differences)
add_executable(week-01-f-same-differences week-01/f-same-differences/main.cpp)
target_compile_options(week-01-f-same-differences PRIVATE -DMAIN_DIR_PATH=${CMAKE_CURRENT_SOURCE_DIR}/week-01/f-same-differences)


project(week-01-g-little-pony-and-expected-maximum)
add_executable(week-01-g-little-pony-and-expected-maximum week-01/g-little-pony-and-expected-maximum/main.cpp)
target_compile_options(week-01-g-little-pony-and-expected-maximum PRIVATE -DMAIN_DIR_PATH=${CMAKE_CURRENT_SOURCE_DIR}/week-01/g-little-pony-and-expected-maximum)


project(week-01-h-string-equality)
add_executable(week-01-h-string-equality week-01/h-string-equality/main.cpp)
target_compile_options(week-01-h-string-equality PRIVATE -DMAIN_DIR_PATH=${CMAKE_CURRENT_SOURCE_DIR}/week-01/h-string-equality)


project(week-01-i-maximum-value)
add_executable(week-01-i-maximum-value week-01/i-maximum-value/main.cpp)
target_compile_options(week-01-i-maximum-value PRIVATE -DMAIN_DIR_PATH=${CMAKE_CURRENT_SOURCE_DIR}/week-01/i-maximum-value)


project(week-01-j-interesting-drink)
add_executable(week-01-j-interesting-drink week-01/j-interesting-drink/main.cpp)
target_compile_options(week-01-j-interesting-drink PRIVATE -DMAIN_DIR_PATH=${CMAKE_CURRENT_SOURCE_DIR}/week-01/j-interesting-drink)


project(week-02-a-meeting-on-the-line)
add_executable(week-02-a-meeting-on-the-line week-02/a-meeting-on-the-line/main.cpp)
target_compile_options(week-02-a-meeting-on-the-line PRIVATE -DMAIN_DIR_PATH=${CMAKE_CURRENT_SOURCE_DIR}/week-02/a-meeting-on-the-line)


project(week-02-b-minimum-notation)
add_executable(week-02-b-minimum-notation week-02/b-minimum-notation/main.cpp)
target_compile_options(week-02-b-minimum-notation PRIVATE -DMAIN_DIR_PATH=${CMAKE_CURRENT_SOURCE_DIR}/week-02/b-minimum-notation)


project(week-02-c-prefixes-and-suffixes)
add_executable(week-02-c-prefixes-and-suffixes week-02/c-prefixes-and-suffixes/main.cpp)
target_compile_options(week-02-c-prefixes-and-suffixes PRIVATE -DMAIN_DIR_PATH=${CMAKE_CURRENT_SOURCE_DIR}/week-02/c-prefixes-and-suffixes)


project(week-02-d-fedya-and-array)
add_executable(week-02-d-fedya-and-array week-02/d-fedya-and-array/main.cpp)
target_compile_options(week-02-d-fedya-and-array PRIVATE -DMAIN_DIR_PATH=${CMAKE_CURRENT_SOURCE_DIR}/week-02/d-fedya-and-array)


project(week-02-e-dora-and-search)
add_executable(week-02-e-dora-and-search week-02/e-dora-and-search/main.cpp)
target_compile_options(week-02-e-dora-and-search PRIVATE -DMAIN_DIR_PATH=${CMAKE_CURRENT_SOURCE_DIR}/week-02/e-dora-and-search)


project(week-02-f-moscow-gorillas)
add_executable(week-02-f-moscow-gorillas week-02/f-moscow-gorillas/main.cpp)
target_compile_options(week-02-f-moscow-gorillas PRIVATE -DMAIN_DIR_PATH=${CMAKE_CURRENT_SOURCE_DIR}/week-02/f-moscow-gorillas)


project(week-02-g-matching-numbers)
add_executable(week-02-g-matching-numbers week-02/g-matching-numbers/main.cpp)
target_compile_options(week-02-g-matching-numbers PRIVATE -DMAIN_DIR_PATH=${CMAKE_CURRENT_SOURCE_DIR}/week-02/g-matching-numbers)


project(week-02-h-moving-dots)
add_executable(week-02-h-moving-dots week-02/h-moving-dots/main.cpp)
target_compile_options(week-02-h-moving-dots PRIVATE -DMAIN_DIR_PATH=${CMAKE_CURRENT_SOURCE_DIR}/week-02/h-moving-dots)


project(week-03-a-exponential-equation)
add_executable(week-03-a-exponential-equation week-03/a-exponential-equation/main.cpp)
target_compile_options(week-03-a-exponential-equation PRIVATE -DMAIN_DIR_PATH=${CMAKE_CURRENT_SOURCE_DIR}/week-03/a-exponential-equation)


project(week-03-b-paint-the-numbers)
add_executable(week-03-b-paint-the-numbers week-03/b-paint-the-numbers/main.cpp)
target_compile_options(week-03-b-paint-the-numbers PRIVATE -DMAIN_DIR_PATH=${CMAKE_CURRENT_SOURCE_DIR}/week-03/b-paint-the-numbers)


project(week-03-c-the-number-of-products)
add_executable(week-03-c-the-number-of-products week-03/c-the-number-of-products/main.cpp)
target_compile_options(week-03-c-the-number-of-products PRIVATE -DMAIN_DIR_PATH=${CMAKE_CURRENT_SOURCE_DIR}/week-03/c-the-number-of-products)


project(week-03-d-divisible-numbers-hard-version)
add_executable(week-03-d-divisible-numbers-hard-version week-03/d-divisible-numbers-hard-version/main.cpp)
target_compile_options(week-03-d-divisible-numbers-hard-version PRIVATE -DMAIN_DIR_PATH=${CMAKE_CURRENT_SOURCE_DIR}/week-03/d-divisible-numbers-hard-version)


project(week-03-e-beautiful-graph)
add_executable(week-03-e-beautiful-graph week-03/e-beautiful-graph/main.cpp)
target_compile_options(week-03-e-beautiful-graph PRIVATE -DMAIN_DIR_PATH=${CMAKE_CURRENT_SOURCE_DIR}/week-03/e-beautiful-graph)


project(week-03-f-mashmokh-and-acm)
add_executable(week-03-f-mashmokh-and-acm week-03/f-mashmokh-and-acm/main.cpp)
target_compile_options(week-03-f-mashmokh-and-acm PRIVATE -DMAIN_DIR_PATH=${CMAKE_CURRENT_SOURCE_DIR}/week-03/f-mashmokh-and-acm)


project(week-03-g-enlarge-gcd)
add_executable(week-03-g-enlarge-gcd week-03/g-enlarge-gcd/main.cpp)
target_compile_options(week-03-g-enlarge-gcd PRIVATE -DMAIN_DIR_PATH=${CMAKE_CURRENT_SOURCE_DIR}/week-03/g-enlarge-gcd)


project(week-03-h-wish-i-knew-how-to-sort)
add_executable(week-03-h-wish-i-knew-how-to-sort week-03/h-wish-i-knew-how-to-sort/main.cpp)
target_compile_options(week-03-h-wish-i-knew-how-to-sort PRIVATE -DMAIN_DIR_PATH=${CMAKE_CURRENT_SOURCE_DIR}/week-03/h-wish-i-knew-how-to-sort)


project(week-03-i-deleting-numbers)
add_executable(week-03-i-deleting-numbers week-03/i-deleting-numbers/main.cpp)
target_compile_options(week-03-i-deleting-numbers PRIVATE -DMAIN_DIR_PATH=${CMAKE_CURRENT_SOURCE_DIR}/week-03/i-deleting-numbers)

